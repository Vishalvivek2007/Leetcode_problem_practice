/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool dfssearch(TreeNode* root, TreeNode* check){
    if(root==check){
        return true;
    }
    else if(root==NULL){
        return false;
    }
    bool left=dfssearch(root->left, check);
    bool right=dfssearch(root->right, check);
    if(left || right){
        return true;
    }
    else{
        return false;
    }
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        bool qleft= dfssearch(root->left, q);
        bool qright=dfssearch(root->right,q);
        if(root==p){
            if(qleft || qright){
                return root;
            }
        }
        bool pleft= dfssearch(root->left, p);
        bool pright=dfssearch(root->right,p );
        if(root==q){
            if(pleft||pright){
                return root;
            }
        }
        if((pleft && qright)||(pright && qleft)){
            return root;
        }
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p,q);
        if(left==NULL){
            return right;
        }
        else{
            return left;
        }
    }
};