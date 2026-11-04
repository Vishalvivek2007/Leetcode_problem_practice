class Solution {
  public:
      int dfs(int i , int j , vector<vector<int>>& matrix , vector<vector<int>>& visited , vector<vector<int>>& value){
          if(visited[i][j]){
              return value[i][j];
          }
          int n=matrix.size() , m=matrix[0].size();
          visited[i][j]=1;
          int max=1;
          if(i>0 && matrix[i-1][j]> matrix[i][j]){
              int temp=1+dfs(i-1 , j , matrix , visited , value);
              if(temp>max){
                  max=temp;
              }
          }
          if(j>0 && matrix[i][j-1]> matrix[i][j]){
              int temp=1+dfs(i , j-1 , matrix , visited , value);
              if(temp>max){
                  max=temp;
              }
          }
          if(i<n-1 && matrix[i+1][j]> matrix[i][j]){
              int temp=1+dfs(i+1 , j , matrix , visited , value);
              if(temp>max){
                  max=temp;
              }
          }
          if(j<m-1 && matrix[i][j+1]> matrix[i][j]){
              int temp=1+dfs(i , j+1 , matrix , visited , value);
              if(temp>max){
                  max=temp;
              }
          }
          value[i][j]=max;
          return max;
      }
      int longestIncreasingPath(vector<vector<int>>& matrix) {
          vector<vector<int>> visited(matrix.size() , vector(matrix[0].size() ,0 ));
          vector<vector<int>> value(matrix.size() , vector(matrix[0].size() ,1 ));
          int n=matrix.size() , m=matrix[0].size();
          int max=-1;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  int temp=dfs(i , j , matrix , visited ,value);
                  if(temp>max){
                      max=temp;
                  }
              }
          }
          return max;
      }
  };