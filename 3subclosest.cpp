class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int best = nums[0] + nums[1] + nums[2]; // starting sum for comparision

        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k]; // current sum / new sum of triplets

                if(abs(sum - target) < abs(best - target)){
                    best = sum;
                }

                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return best;
    }
};
