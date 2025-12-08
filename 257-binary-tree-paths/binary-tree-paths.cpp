class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* node, string s) {
        if (!node->left && !node->right) {
            ans.push_back(s);
            return;
        }
        if (node->left) dfs(node->left, s + "->" + to_string(node->left->val));
        if (node->right) dfs(node->right, s + "->" + to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, to_string(root->val));
        return ans;
    }
};
