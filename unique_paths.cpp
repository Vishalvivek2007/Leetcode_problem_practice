class Solution {
  public:
      int uniquePaths(int m, int n) {
          vector<vector<int>> graph(m ,vector<int>(n ,0));
          graph[0][0]=1;
          for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                  if(i==0 && j==0){
                      continue;
                  }
                  if(i==0){
                      graph[i][j]+=graph[i][j-1];
                  }
                  else if(j==0){
                      graph[i][j]+=graph[i-1][j];
                  }
                  else{
                      graph[i][j]+=graph[i-1][j]+graph[i][j-1];
                  }
              }
          }
          return graph[m-1][n-1];
      }
  };