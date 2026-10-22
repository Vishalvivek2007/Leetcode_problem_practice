class Solution {
  public:
      int change(int amount, vector<int>& coins) {
          vector<vector<long long>> DP(
              amount + 1, vector<long long>(coins.size(), 0)
          );
  
          for (int i = 0; i <= amount; i++) {
              long long prev = 0;
  
              for (int j = 0; j < coins.size(); j++) {
                  if (i == 0) {
                      DP[i][j] = 1;
                      continue;
                  }
  
                  if (coins[j] > i) {
                      DP[i][j] = prev;
                  } else {
                      DP[i][j] = min(
                          DP[i - coins[j]][j] + prev,
                          (long long)INT_MAX
                      );
                  }
  
                  prev = DP[i][j];
              }
          }
  
          return DP[amount][coins.size() - 1];
      }
  };