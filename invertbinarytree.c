/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swap(struct TreeNode** node1, struct TreeNode** node2){
    struct TreeNode* temp = *node1;
    *node1=*node2;
    *node2=temp;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root==NULL){
        return root;
    }
    if(root->left==NULL && root->right==NULL){
        return root;
    }
    swap(&root->right, &root->left);
    invertTree(root->right);
    invertTree(root->left);
    return root;
}