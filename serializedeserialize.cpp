
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string& s) {
        if (!root) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserializeHelper(vector<string>& nodes, int& idx) {
        if (nodes[idx] == "N") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = deserializeHelper(nodes, idx);
        root->right = deserializeHelper(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string cur;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        int idx = 0;
        return deserializeHelper(nodes, idx);
    }
};