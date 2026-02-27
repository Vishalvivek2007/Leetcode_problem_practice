/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int max(int a, int b){
    if(a>b){
        return a;

    }
    else{
        return b;
    }
}

int check=0;

int height(struct TreeNode* root, int h){
    if(root==NULL){
        return h;
    }
    int left=height(root->left, h+1);
    int right =height(root->right,h+1);
    int sub=left-right;
    if(sub<0){
        sub=sub*-1;
    }
    if(sub>1){
        check=1;
    }
    return max(left,right);
}

bool isBalanced(struct TreeNode* root) {
    check=0;
    if(root==NULL){
        return true;
    }
    int sub= height(root->left,0)-height(root->right,0);
    if(check==1){
        return false;
    }
    if(sub<0){
        sub=sub*-1;
    }
    if(sub<=1){
        return true;
    }

    return false;
}