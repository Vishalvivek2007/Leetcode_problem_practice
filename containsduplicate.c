bool containsDuplicate(int* nums, int len) {
    int max=nums[0],min=nums[0];
    for(int i=0;i<len;i++){
        if(nums[i]>max){
            max=nums[i];
        }
        if(nums[i]<min){
            min=nums[i];
        }
    }
    if(min<0){
        min=min*-1;
        if(min>max){
            max=min;
        }
    }
    int* arr = (int*)calloc(2*max+1,sizeof(int));
    for(int i=0;i<len;i++){
        if(nums[i]>0){
            arr[nums[i]+max]++;
            if(arr[nums[i]+max]>1){
                return true;
            }
        }
        else{
            arr[nums[i]*-1]++;
            if(arr[nums[i]*-1]>1){
                return true;
            }
        }
    }
    return false;
}