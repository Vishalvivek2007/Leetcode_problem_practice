char pop(char* arr, int* top){
    if(*top==0){
        return 'a';
    }
    char temp = arr[*top];
    (*top)--;
    return temp;
}

void insert(char* arr, int* top, char item){
    (*top)++;
    arr[*top]=item;
    return;
}

bool isValid(char* str){
    int len = strlen(str);
    char* arr = (char*)malloc(sizeof(char)*(len+1));
    int top=0;
    for(int i=0;i<len;i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            insert(arr, &top, str[i]);
        }
        else{
            char temp =pop(arr,&top);
            if(temp=='a'){
                return false;
            }
            if(str[i]==')' && temp!='('){
                return false;
            }
            if(str[i]==']' && temp !='['){
                return false;
            }
            if(str[i]=='}' && temp !='{'){
                return false;
            }
        }
    }
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}