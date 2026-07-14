class Solution {
  public:
      int recursive(vector<int>& coins, vector<int>& dp, int amount) {
          if (amount == 0) {
              return 0;
          }
  
          if (dp[amount] != 0) return dp[amount];   // CHANGE: Memoization check
  
          int min = 100000;
  
          for (int i = 0; i < coins.size(); i++) {
              if (coins[i] <= amount) {
  
                  if (!dp[amount - coins[i]]) {
                      recursive(coins, dp, amount - coins[i]);
                  }
  
                  // CHANGE: Ignore impossible states
                  if (dp[amount - coins[i]] != -1) {
                      if (min > 1 + dp[amount - coins[i]]) {
                          min = 1 + dp[amount - coins[i]];
                      }
                  }
              }
          }
  
          dp[amount] = (min == 100000) ? -1 : min;
          return dp[amount];
      }
  
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount + 1, 0);
          recursive(coins, dp, amount);
          return dp[amount];
      }
  };