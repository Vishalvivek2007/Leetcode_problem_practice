class Solution {
public:
    bool first = true;

    bool inorder(TreeNode* node, long long& prev){

        if(node == NULL) return true;

        if(!inorder(node->left, prev))
            return false;

        if(!first && node->val <= prev)
            return false;

        first = false;
        prev = node->val;

        return inorder(node->right, prev);
    }

    bool isValidBST(TreeNode* root) {

        long long prev = LLONG_MIN;

        return inorder(root, prev);
    }
};