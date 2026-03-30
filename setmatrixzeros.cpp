class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> col(matrix[0].size(),0);
        vector<int> row(matrix.size(), 0);
        for(int i=0;i<matrix.size(); i++){
            for(int j=0;j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int z=0;z<matrix.size();z++){
            if(row[z]>0){
                for(int i=0;i<matrix[0].size();i++){
                    matrix[z][i]=0;
                }
            }
        }
        for(int z=0;z<matrix[0].size();z++){
            if(col[z]>0){
                for(int i=0;i<matrix.size();i++){
                    matrix[i][z]=0;
                }
            }
        }
        return ;
    }
};