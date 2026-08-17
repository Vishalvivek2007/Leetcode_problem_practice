class Solution {
  public:
      bool wordBreak(string s, vector<string>& wordDict) {
  
          int n = s.length();
  
          vector<bool> dp(n + 1, false);
  
          dp[0] = true;
  
          for (int i = 0; i < n; i++) {
  
              if (!dp[i])
                  continue;
  
              for (string word : wordDict) {
  
                  int len = word.length();
  
                  if (i + len <= n &&
                      s.substr(i, len) == word) {
  
                      dp[i + len] = true;
                  }
              }
          }
  
          return dp[n];
      }
  };