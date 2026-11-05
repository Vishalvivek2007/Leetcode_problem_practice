class Solution {
  int dfs(int i, int j, const string& s, const string& t, vector<vector<int>>& memo) {
      if (j == t.size()) return 1;
      if (i == s.size()) return 0;

      if (memo[i][j] != -1) return memo[i][j];

      if (s[i] == t[j]) {
          return memo[i][j] = dfs(i + 1, j + 1, s, t, memo) + dfs(i + 1, j, s, t, memo);
      }

      return memo[i][j] = dfs(i + 1, j, s, t, memo);
  }

public:
  int numDistinct(string s, string t) {
      vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
      return dfs(0, 0, s, t, memo);
  }
};