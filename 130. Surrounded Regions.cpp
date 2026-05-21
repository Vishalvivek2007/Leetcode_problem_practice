class Solution {
public:
    void bfs(int i , int j, vector<vector<char>>& board ,
             vector<vector<bool>>& visited){

        visited[i][j]=true;

        int n = board.size();
        int m = board[0].size();

        if(i+1<n && board[i+1][j]=='O' && !visited[i+1][j]){
            bfs(i+1,j,board,visited);
        }

        if(j+1<m && board[i][j+1]=='O' && !visited[i][j+1]){
            bfs(i,j+1,board,visited);
        }

        if(i-1>=0 && board[i-1][j]=='O' && !visited[i-1][j]){
            bfs(i-1,j,board,visited);
        }

        if(j-1>=0 && board[i][j-1]=='O' && !visited[i][j-1]){
            bfs(i,j-1,board,visited);
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        // left boundary
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                bfs(i,0,board,visited);
            }
        }

        // top boundary
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !visited[0][j]){
                bfs(0,j,board,visited);
            }
        }

        // right boundary
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                bfs(i,m-1,board,visited);
            }
        }

        // bottom boundary
        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O' && !visited[n-1][j]){
                bfs(n-1,j,board,visited);
            }
        }

        // flip surrounded O
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};