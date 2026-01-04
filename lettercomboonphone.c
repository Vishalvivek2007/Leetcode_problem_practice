/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


char * insertatlast(char *str, char letter){
  int len=0;
  while(str[len]!='\0'){
    len++;
  }
  char* ans=(char*)malloc(sizeof(char)*(len+2));
  for(int i=0;i<len;i++){
    ans[i]=str[i];
  }
  ans[len]=letter;
  ans[len+1]='\0';
  return ans;
}

void getcombos(char key[10][5], char** arr,int* arrlen,char* temp1, char* temp2){
    int len=0;
    while(temp1[len]!=0){
        len++;
    }
    if(temp2[0]=='\0'){
        arr[*arrlen]=(char *)malloc(sizeof(char)*(len+1));
        strcpy(arr[*arrlen],temp1);
        (*arrlen)++;
        return;
    }   
    char front = temp2[0];
    for(int i=1;i<=key[front-'0'][0]-'0';i++){
        char* temp3= insertatlast(temp1, key[front-'0'][i]);
        getcombos(key,arr,arrlen,temp3,temp2+1);
    }

}

char** letterCombinations(char* numbers, int* arrlen) {
    int len=0;
    *arrlen=0;
    while(numbers[len]!='\0'){
        len++;
    }
    char** arr = (char**)malloc(sizeof(char*)*pow(4,len));
    if(len==0){
        arr[0]=(char*)malloc(sizeof(char)*1);
        arr[0][0]='\0';
        return arr;
    }
    char str[100];
    str[0]='\0';
    char key[10][5]={{},{},{'3','a','b','c'},{'3','d','e','f'},{'3','g','h','i'},{'3','j','k','l'},{'3','m','n','o'},{'4','p','q','r','s'},{'3','t','u','v'},{'4','w','x','y','z'}};
    getcombos(key, arr, arrlen,str,numbers);
    return arr;
}