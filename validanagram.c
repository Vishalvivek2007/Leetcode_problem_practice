
bool isAnagram(char* s, char* t) {
    int* freq1 = (int*)malloc(sizeof(int)*27);
    int* freq2 = (int*)malloc(sizeof(int)*27);
    for(int i=0;i<27;i++){
        freq1[i]=0;
        freq2[i]=0;
    }
    int len1=0,len2=0;
    while(s[len1]!='\0'){
        len1++;
    }
    while(t[len2]!='\0'){
        len2++;
    }
    if(len1!=len2){
        return false;
    }
    for(int i=0;i<len1;i++){
        char temp =s[i];
        freq1[temp-'a']++;
        temp=t[i];
        freq2[temp-'a']++;
    }
    for(int i=0;i<27;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    free(freq1);
    free(freq2);
    return true;
}