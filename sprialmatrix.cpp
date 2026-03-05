class Solution {
public:
    void spiral(vector<vector<int>>& matrix, vector<int>& list, int m, int n, int adjust){
    if(m < 0 || n < 0) return;
    for(int i = adjust; i <= n + adjust; i++)  
        list.push_back(matrix[adjust][i]);

    for(int i =1+adjust; i <= m + adjust; i++)
        list.push_back(matrix[i][n + adjust]);

    if(m != 0)  
        for(int i = n + adjust - 1; i >= adjust; i--)
            list.push_back(matrix[m + adjust][i]);

    if(n != 0)  
        for(int i = m + adjust - 1; i > adjust; i--)
            list.push_back(matrix[i][adjust]);

    spiral(matrix, list, m-2, n-2, adjust+1);
}
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> list;
        spiral(matrix,list, matrix.size()-1, matrix[0].size()-1,0);
        return list; 
    }
};