class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curr = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);  // restart or extend?
            maxSum = max(maxSum, curr);
        }
        return maxSum;
    }
};