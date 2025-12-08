class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* n, string &path) {
        if (!n->left && !n->right) {
            ans.push_back(path);
            return;
        }
        int old = path.size();
        if (n->left) {
            path += "->" + to_string(n->left->val);
            dfs(n->left, path);
            path.resize(old);
        }
        if (n->right) {
            path += "->" + to_string(n->right->val);
            dfs(n->right, path);
            path.resize(old);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        dfs(root, path);
        return ans;
    }
};
