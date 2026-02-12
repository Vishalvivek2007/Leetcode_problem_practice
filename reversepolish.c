struct stack{
    int * arr;
    int top;
    int capacity;
};

int getnum(char * arr){
    int temp=0,sign=1;
    int count=0;
    while(arr[count]!='\0'){
        temp=temp*10;
        if(count==0){
            if(arr[0]=='-'){
                sign=-1;
                count++;
                continue;
            }
        }
        temp+=arr[count]-'0';
        count++;
    }
    return temp*sign;
}


struct stack* createstack(int capacity){
    struct stack* ans = (struct stack*)malloc(sizeof(struct stack));
    ans->arr = (int*)malloc(sizeof(int)*capacity);
    ans->capacity=capacity;
    ans->top=0;
    return ans;
}


void insert(struct stack* st, int num){
    st->arr[st->top]=num;
    st->top= st->top+1;
    return;
}

int pop(struct stack* st){
    st->top = st->top -1;
    return st->arr[st->top];
}

int evalRPN(char** arr, int len) {
    struct stack* st = createstack(len);
    for(int i=0;i<len;i++){
        if(strlen(arr[i])==1 && (arr[i][0]=='+'||arr[i][0]=='-'|| arr[i][0]=='*'|| arr[i][0]=='/')){
            int right= pop(st);
            int left =pop(st);
            int temp=0;
            if(arr[i][0]=='+'){
                temp = left+right;
            }
            else if(arr[i][0]=='-'){
                temp = left-right;
            }
            else if(arr[i][0]=='*'){
                temp  =left*right;
            }
            else if(arr[i][0]=='/'){
                temp  = left/right;
            }
            insert(st, temp);
        }
        else{
            insert(st, getnum(arr[i]));
        }
    }
    return pop(st);
}