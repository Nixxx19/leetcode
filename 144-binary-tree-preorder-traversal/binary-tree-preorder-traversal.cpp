class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            res.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return res;
    }
};
