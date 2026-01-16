#define MAP_LEN 20011

struct node{
    char* sortedstr;   
    int mindex;
    int clen;
};

void sort(char* arr, int left, int right){
    int freq[26] = {0};

    for (int i = left; i <= right; i++)
        freq[arr[i] - 'a']++;

    int idx = left;
    for (int c = 0; c < 26; c++){
        while (freq[c]--){
            arr[idx++] = c + 'a';
        }
    }
}

struct node* createnode(char* sorted, int index){
    struct node* ans = malloc(sizeof(struct node));
    ans->sortedstr = strdup(sorted);  
    ans->mindex = index;              
    ans->clen = 0;
    return ans;
}

int gethash(char* str){
    int h = 0;
    for(int i = 0; str[i]; i++)
        h = (h * 31 + str[i]) % MAP_LEN;
    return h;
}

char*** groupAnagrams(char** arr, int len, int* flen, int** clenarr) {
    *flen = 0;
    char*** farr = NULL;
    *clenarr = NULL;  
    struct node** hash = calloc(MAP_LEN, sizeof(struct node*));
    for(int i = 0; i < len; i++){

        char* temp = strdup(arr[i]); 
        sort(temp, 0, strlen(temp) - 1);
        int index = gethash(temp);

        while(hash[index] && strcmp(temp, hash[index]->sortedstr) != 0)
            index = (index + 1) % MAP_LEN;

        if(hash[index] == NULL){

            hash[index] = createnode(temp, *flen);
            farr = realloc(farr, sizeof(char**) * (*flen + 1));
            farr[*flen] = NULL;
            *clenarr = realloc(*clenarr, sizeof(int) * (*flen + 1));
            (*clenarr)[*flen] = 0;
            (*flen)++;
        }

        int g = hash[index]->mindex;

        farr[g] = realloc(farr[g], sizeof(char*) * (hash[index]->clen + 1));
        farr[g][hash[index]->clen] = strdup(arr[i]);

        hash[index]->clen++;
        (*clenarr)[g]++;               
        free(temp);                    
    }

    return farr;
}
