class Solution {
public:
    void explore(int n, int m, vector<vector<int>>& graph, 
                 vector<vector<char>>& grid, int i, int j) {
        
        if(i < 0 || i >= n || j < 0 || j >= m || 
           graph[i][j] == 1 || grid[i][j] == '0') {
            return;
        }

        graph[i][j] = 1;

        explore(n, m, graph, grid, i - 1, j);
        explore(n, m, graph, grid, i, j - 1);
        explore(n, m, graph, grid, i + 1, j);
        explore(n, m, graph, grid, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;

        vector<vector<int>> graph(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!graph[i][j] && grid[i][j] == '1') {
                    count++;
                    explore(n, m, graph, grid, i, j);
                }
            }
        }

        return count;
    }
};