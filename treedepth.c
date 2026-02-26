/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int left, int right ){
    if(left>right){
        return left;
    }
    else{
        return right;
    }
}
int dfs(struct TreeNode* root, int count){
    if(root==NULL){
        return count;
    }
    int left=dfs(root->left, count+1);
    int right=dfs(root->right, count+1);
    return max(left, right);
}


int maxDepth(struct TreeNode* root) {
    if(root==NULL){
        return 0;
    }
    int ans =dfs(root, 0);
    return ans;
}