class Solution {
public:
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, 
                        int& pre, int& in, long stop) {
        if (pre == preorder.size()) return NULL;
        if (inorder[in] == stop) {     // boundary hit — subtree done
            in++;                       // consume root from inorder
            return NULL;
        }
        
        TreeNode* ans = new TreeNode(preorder[pre++]);
        ans->left  = construct(preorder, inorder, pre, in, ans->val);
        ans->right = construct(preorder, inorder, pre, in, stop);
        return ans;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0, in = 0;
        return construct(preorder, inorder, pre, in, LONG_MAX);
    }
};