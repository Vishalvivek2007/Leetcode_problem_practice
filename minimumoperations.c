int minOperations(int* arr, int len, int k) {
    int count=0;
    for(int i=0;i<len;i++){
        count=(count+arr[i])%k;
    }
    return count;
}