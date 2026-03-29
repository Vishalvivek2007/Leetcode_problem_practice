class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int right = arr.size()-1;
        while(right>=0){
            if(arr[right]<9){
                arr[right]++;
                return arr;
            }
            else{
                arr[right]=0;
                if(right==0){
                    arr.insert(arr.begin(),1);
                }
            }
            right--;
        }
        return arr;
    }
};