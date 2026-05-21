class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        queue<vector<int>> q;

        int fresh=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int minutes =0;
        while(!q.empty() && fresh>0){
            int size= q.size();
            for(int i=0;i<size;i++){
                vector<int> curr = q.front();
                q.pop();
                int x=curr[0];
                int y=curr[1];
                // UP
                if(x-1 >= 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    fresh--;
                    q.push({x-1, y});
                }

                // DOWN
                if(x+1 < rows && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    fresh--;
                    q.push({x+1, y});
                }

                // LEFT
                if(y-1 >= 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    fresh--;
                    q.push({x, y-1});
                }

                // RIGHT
                if(y+1 < cols && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    fresh--;
                    q.push({x, y+1});
                }
            }
            minutes++;
        }
        if(fresh>0){
            return -1;
        }

        return minutes;
    }
};