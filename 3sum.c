/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void merge(int *arr1,int*arr2,int *arr,int len){
  int middle=len/2;
  int i=0,l=0,r=0;
  while(l<middle && r<len-middle){
    if(arr1[l]<arr2[r]){
      arr[i]=arr1[l];
      i++;
      l++;
    }
    else{
      arr[i]=arr2[r];
      i++;
      r++;
    }
  }
  while(l<middle){
    arr[i]=arr1[l];
    i++;
    l++;
  }
  while(r<len-middle){
    arr[i]=arr2[r];
    i++;
    r++;
  }
}

void mergsort(int *arr,int len){
  if(len<=1){
    return;
  }
  int middle=len/2;
  int left[middle];
  int right[len-middle];
  int i=0,j=0;
  for(;i<len;i++){
    if(i<middle){
      left[i]=arr[i];
    }
    else{
      right[j]=arr[i];
      j++;
    }
  }
  mergsort(left,middle);
  mergsort(right,len-middle);
  merge(left,right,arr,len);
}


int** threeSum(int* arr, int len, int* count, int** rclen) {
    mergsort(arr,len);
    int maxlen=len*len;
    *count=0;
    int ** farr= (int**)malloc(sizeof(int*)*maxlen);
    *rclen = (int*)malloc(sizeof(int)*maxlen);

    for(int i=0;i<len-2;i++){

        if(i > 0 && arr[i] == arr[i-1]) continue;

        int target = 0-arr[i];
        int left=i+1, right=len-1;
        while(left<right){
            int sum = arr[left]+arr[right];
            if(sum==target){
                farr[*count]=(int*)malloc(sizeof(int)*3);
                farr[*count][0]=arr[i];
                farr[*count][1]=arr[left];
                farr[*count][2]=arr[right];
                (*rclen)[*count]=3;
                (*count)++;
                while(left < right && arr[left] == arr[left+1]) left++;
                while(left < right && arr[right] == arr[right-1]) right--;
                left++;
                right--;
            }
            else if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
        }
    }
    return farr;
}