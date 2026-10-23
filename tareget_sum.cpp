class Solution {
  public:
      int findTargetSumWays(vector<int>& nums, int amount) {
          int sum = 0;
          for (int i = 0; i < nums.size(); i++) {
              sum += nums[i];
          }
  
          if (nums.empty()) {
              return amount == 0;
          }
  
          if (amount > sum || amount < -sum) {
              return 0;
          }
  
          vector<vector<int>> DP(
              nums.size(), vector<int>(2 * sum + 1, 0)
          );
  
          int temp = 0;
  
          for (int j = 0; j < nums.size(); j++) {
              for (int i = temp + nums[j];
                   i <= 2 * sum - temp - nums[j]; i++) {
  
                  if (j == 0) {
                      if (i + amount - sum == nums[j]) {
                          DP[j][i]++;
                      }
  
                      if (i + amount - sum == -nums[j]) {
                          DP[j][i]++;
                      }
                  }
                  else {
                      DP[j][i] = DP[j - 1][i - nums[j]]
                               + DP[j - 1][i + nums[j]];
                  }
              }
  
              temp += nums[j];
          }
  
          return DP[nums.size() - 1][sum];
      }
  };