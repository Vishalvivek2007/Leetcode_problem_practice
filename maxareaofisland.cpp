class Solution {
public:
    void explore(int n, int m, vector<vector<int>>& graph, vector<vector<int>>& grid, int i, int j, int& sum) {
        if(i < 0 || i >= n || j < 0 || j >= m || graph[i][j] == 1 || grid[i][j] == 0) {
            return;
        }
        sum++;
        graph[i][j] = 1;

        explore(n, m, graph, grid, i - 1, j,sum);
        explore(n, m, graph, grid, i, j - 1,sum);
        explore(n, m, graph, grid, i + 1, j,sum);
        explore(n, m, graph, grid, i, j + 1,sum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        int n =grid.size(), m =grid[0].size();
       vector<vector<int>> graph(n, vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && graph[i][j]==0){
                int temp=0;
                explore(n,m,graph,grid,i,j,temp);
                if(temp>max){
                    max=temp;
                }
            }
        }
       }
       return max;
    }
};