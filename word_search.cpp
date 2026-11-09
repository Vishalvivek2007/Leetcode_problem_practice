class Solution {
  public:
      bool backtrack(vector<vector<char>>&board ,vector<vector<int>>& visited ,  int i , int j , int z ,string& word){
          if(z==word.size()-1){
              return board[i][j]==word[z]?true: false;
          }
          if(board[i][j]!=word[z]){
              return false;
          }
          int n=board.size() , m=board[0].size();
          visited[i][j]=1;
          bool up=false,left=false, right=false , down=false;
          if(j>0 && !visited[i][j-1]){
              left=backtrack(board , visited , i , j-1 , z+1 , word);
          }
          if(j<m-1 && !visited[i][j+1]){
              right=backtrack(board , visited , i , j+1 , z+1 , word);
          }
          if(i<n-1 && !visited[i+1][j]){
              down=backtrack(board , visited , i+1 , j , z+1 , word);
          }
          if(i>0 && !visited[i-1][j]){
              up=backtrack(board , visited ,i-1 , j , z+1 , word);
          }
          visited[i][j]=0;
          return (left||right)||(down||up);
      }
  
      bool exist(vector<vector<char>>& board, string word) {
          int n=board.size() , m=board[0].size();
          vector<vector<int>> visited(n, vector<int>(m , 0));
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(backtrack(board , visited, i , j , 0 , word)){
                      return true;
                  }
              }
          }
          return false;
      }
  };