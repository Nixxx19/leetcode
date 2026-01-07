class Solution {
public:
    long long total = 0, best = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + dfs(root->left) + dfs(root->right);
        best = max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        function<long long(TreeNode*)> sum = [&](TreeNode* n) {
            if (!n) return 0LL;
            return n->val + sum(n->left) + sum(n->right);
        };
        total = sum(root);
        dfs(root);
        return best % MOD;
    }
};
