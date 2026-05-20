class Solution {
public:

    void dfs(int i, int j,vector<vector<int>>&heights, vector<vector<bool>>& visited){
        int n=heights.size();
        int m=heights[0].size();
        visited[i][j]=true;

        if(i-1>=0 && !visited[i-1][j] && heights[i-1][j]>=heights[i][j]){
            dfs(i-1,j,heights,visited);
        }
        if(j-1>=0 && !visited[i][j-1] && heights[i][j-1]>=heights[i][j]){
            dfs(i,j-1,heights,visited);
        }
        if(i+1<=n-1 && !visited[i+1][j] && heights[i+1][j]>=heights[i][j]){
            dfs(i+1,j,heights,visited);
        }
        if(j+1<=m-1 && !visited[i][j+1] && heights[i][j+1]>=heights[i][j]){
            dfs(i,j+1,heights,visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
        }

        // Pacific -> top border
        for(int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
        }

        // Atlantic -> right border
        for(int i = 0; i < n; i++) {
            dfs(i, m - 1, heights, atlantic);
        }

        // Atlantic -> bottom border
        for(int j = 0; j < m; j++) {
            dfs(n - 1, j, heights, atlantic);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};