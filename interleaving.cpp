class Solution {
  public:
      bool dfs(int i, int j, int k, string& s1, string& s2,
               string& s3, vector<vector<int>>& check) {
  
          if(i == s1.size() && j == s2.size()){
              return true;
          }
  
          if(check[i][j] != 0){
              return check[i][j] == 1;
          }
  
          bool left = false;
          bool right = false;
  
          if(i < s1.size() && s1[i] == s3[k]){
              left = dfs(i+1, j, k+1, s1, s2, s3, check);
          }
  
          if(j < s2.size() && s2[j] == s3[k]){
              right = dfs(i, j+1, k+1, s1, s2, s3, check);
          }
  
          if(left || right){
              check[i][j] = 1;
              return true;
          }
  
          check[i][j] = -1;
          return false;
      }
  
      bool isInterleave(string s1, string s2, string s3) {
  
          int n = s1.size();
          int m = s2.size();
  
          if(n + m != s3.size()){
              return false;
          }
  
          vector<vector<int>> check(n+1, vector<int>(m+1, 0));
  
          return dfs(0, 0, 0, s1, s2, s3, check);
      }
  };