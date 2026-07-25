class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n=matrix[0].length, m=matrix.length;
        int left=0, right=m*n-1;
        while(left<=right){
            int middle=(left+right)/2;
            if(matrix[middle/n][middle%n]>target){
                right=middle-1;
            }
            else if (matrix[middle/n][middle%n]<target){
                left=middle+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    
}