/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    int calculate(TreeNode* root, int max){
        if(root==NULL){
            return 0;
        }
        if(root->val>=max){
            max=root->val;
            count++;
        }
        if(root->right){
            calculate(root->right,max);
        }
        if(root->left){
            calculate(root->left, max);
        }
        return count;
    }
    int goodNodes(TreeNode* root) {
        calculate(root, INT_MIN);
        return count;
    }
};