int calvol(int a, int b, int dis){
    if(a>b){
        return b*dis;
    }
    else{
        return a*dis;
    }
}

int maxArea(int* arr, int len) {
    int vol=-1;
    int left=0, right =len-1;
    while(left<right){
        int temp = calvol(arr[left], arr[right], right-left);
        if(temp>vol){
            vol=temp;
        }
        if(arr[left]<arr[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return vol;
}