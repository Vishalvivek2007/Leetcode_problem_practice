bool isPalindrome(char* s) {
    int len = strlen(s);
    char* str  =(char*)malloc(sizeof(char)*(len+1));
    int temp=0;
    for(int i=0;i<len;i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            if(s[i]>='A' && s[i]<='Z'){
                str[temp]=s[i]+32;
            }
            else{
                str[temp]=s[i];
            }
            temp++;
        }
    }
    int i=0,j=temp-1;
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}