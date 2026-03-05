int max(int a , int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int lengthOfLongestSubstring(char* s) {
    char* temp =s;
    int len =0;
    while(*temp !='\0'){
        temp++;
        len++;
    }
    if(len<=1){
        return len;
    }

    int present[256],l=0,ans=0;
    for(int i=0;i<256;i++){
        present[i]=-1;
    }

    for(int r=0;r<len;r++){
        int index = *(s+r);
        if(present[index]>=l){
            l=present[index]+1;
        }
        ans=max(ans, r-l+1); 
        present[index]=r;
    }
    return ans;
}