char* convert(char* s, int rows) {
    int jump=-1;
    if(rows==1){
        return s;
    }
    else {
        int len=0,lentemp=0;
        while(s[len]!='\0'){
            len++;
        }
        char* temp = (char*)malloc(sizeof(char)*(len+1));
        for(int i=0;i<rows;i++){
            int index=i;
            for(int count=0;index<len;count++){
                if(jump!=0){
                    temp[lentemp]=s[index];
                    lentemp++;
                }
                if(count%2==0){
                    jump=(rows-1)*2-2*i;
                }
                else{
                    jump=2*i;
                }
                index+=jump;
            }
        }
        temp[lentemp]='\0';
        return temp;
    }
    
}