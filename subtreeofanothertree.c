/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isequal(struct TreeNode* a, struct TreeNode* b){
    if(a==NULL && b==NULL){
        return true;
    }   
    if(a==NULL && b!=NULL || a!=NULL && b==NULL){
        return false;
    }
    if(a->val!=b->val){
        return false;
    }
    bool left = isequal(a->left, b->left);
    bool right=isequal(a->right, b->right);
    if(left && right){
        return true;
    }
    else{
        return false;
    }
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root==NULL && subRoot==NULL){
        return true;
    }
    if(root==NULL && subRoot!=NULL || root!=NULL && subRoot==NULL){
        return false;
    }
    bool mid=isequal(root,subRoot);
    bool left=isSubtree(root->left,subRoot);
    bool right=isSubtree(root->right,subRoot);
    if(mid|| left|| right){
        return true;
    }
    else{
        return false;
    }
}