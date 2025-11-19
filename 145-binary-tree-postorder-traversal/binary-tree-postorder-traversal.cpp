class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            dfs(node->right);
            res.push_back(node->val);
        };
        dfs(root);
        return res;
    }
};
