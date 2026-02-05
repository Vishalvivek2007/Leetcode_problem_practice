/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* productExceptSelf(int* arr, int len, int* rlen) {
    *rlen=len;
    int* farr=(int*)malloc(sizeof(int)*len);
    int* preprod=(int*)malloc(sizeof(int)*len);
    int* postprod=(int*)malloc(sizeof(int)*len);
    preprod[0]=1;
    postprod[len-1]=1;
    for(int i=1;i<len;i++){
        preprod[i]=arr[i-1]*preprod[i-1];
    }
    for(int i=len-2;i>=0;i--){
        postprod[i]=arr[i+1]*postprod[i+1];
    }
    for(int i=0;i<len;i++){
        if(i==0){
            farr[i]=postprod[i];
        }
        else if(i==len-1){
            farr[i]=preprod[i];
        }
        else{
            farr[i]=postprod[i]*preprod[i];
        }
    }
    free(preprod);
    free(postprod);
    return farr;
}