class Solution {
  public:
      int longestCommonSubsequence(string str1, string str2) {
          int m =str1.size() , n = str2.size();
          vector<vector<int>> matrix(m+1 , vector<int>(n+1, 0));
          for(int i=0;i<=m;i++){
              for(int j=0;j<=n;j++){
                  if(i==0||j==0){
                      continue;
                  }
                  if(str1[i-1]==str2[j-1]){
                      matrix[i][j]=matrix[i-1][j-1]+1;
                  }
                  else{
                      matrix[i][j]=max(matrix[i-1][j] , matrix[i][j-1]);
                  }
              }
          }
          return matrix[m][n];
      }
  };