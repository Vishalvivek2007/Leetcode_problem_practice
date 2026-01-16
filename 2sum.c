/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct node{
    int value;
    int index;
};

int gethash(int n, int size){
    if(n<0){
        n=n*-1;
    }
    return n%size;
}


int ispresent(struct node** hash, int number,int len){
    int index = gethash(number,len);
    while(hash[index]){
        if(hash[index]->value==number){
            return 1;
        }
        index=(index+1)%len;
    }
    return 0;
}


int getindex(struct node** hash,int number, int len ){
    int index= gethash(number,len);
    while(hash[index]){
        if(hash[index]->value==number){
            return hash[index]->index;
        }
        index=(index+1)%len;
    }
    return -1;
}

void storeval(struct node** hash, int val , int i, int len){
    int index= gethash(val,len);
    while(hash[index]){
        index = (index+1)%len;
    }
    hash[index]=(struct node*)malloc(sizeof(struct node));
    hash[index]->value = val;
    hash[index]->index= i;
    return ;
}




int* twoSum(int* arr, int len, int target, int* flen){
    struct node** hash =(struct node*)calloc(len*2, sizeof(struct node));
    int* farr =(int*)malloc(sizeof(int)*2);
    *flen=2;
    for(int i=0;i<len;i++){
        int temp = target-arr[i];
        if(ispresent(hash,temp,2*len)){
            farr[0]=i;
            farr[1]=getindex(hash,temp,2*len);
            return farr;
        }
        else{
            storeval(hash,arr[i],i,2*len);
        }
    }
    return farr;
}