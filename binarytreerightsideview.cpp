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
    void rightprint(TreeNode* root, int height, vector<int>& harr, vector<int>& valarr){
        if(root==NULL){
            return;
        }
        if(height>harr.size()){
            harr.push_back(root->val);
            valarr.push_back(root->val);
            rightprint(root->right,height+1, harr, valarr);
            rightprint(root->left, height+1, harr, valarr);
            return;
        }
        else{
            rightprint(root->right,height+1, harr, valarr);
            rightprint(root->left, height+1, harr, valarr);
            return;
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> harr, valarr;
        rightprint(root, 1, harr, valarr);
        return valarr;
    }
};