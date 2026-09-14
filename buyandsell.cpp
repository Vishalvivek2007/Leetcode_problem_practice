class Solution {
  public:
      int maxProfit(vector<int>& prices) {
          int n = prices.size();
          vector<vector<int>> dp(n, vector<int>(2, -1));
          return dfs(0, 1, prices, dp);
      }
  
  private:
      int dfs(int i, int buying, vector<int>& prices,
              vector<vector<int>>& dp) {
  
          if (i >= prices.size()) {
              return 0;
          }
  
          if (dp[i][buying] != -1) {
              return dp[i][buying];
          }
  
          int cooldown = dfs(i + 1, buying, prices, dp);
  
          if (buying) {
              int buy = dfs(i + 1, 0, prices, dp) - prices[i];
              dp[i][buying] = max(buy, cooldown);
          } 
          else {
              int sell = dfs(i + 2, 1, prices, dp) + prices[i];
              dp[i][buying] = max(sell, cooldown);
          }
  
          return dp[i][buying];
      }
  };