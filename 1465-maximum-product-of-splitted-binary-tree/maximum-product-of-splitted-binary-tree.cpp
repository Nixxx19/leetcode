class Solution {
public:
    const int MOD = 1e9 + 7;
    long long total = 0, ans = 0;

    long long solve(TreeNode* root) {
        if (!root) return 0;
        long long l = solve(root->left);
        long long r = solve(root->right);
        long long cur = root->val + l + r;
        ans = max(ans, cur * (total - cur));
        return cur;
    }

    int maxProduct(TreeNode* root) {
        function<long long(TreeNode*)> calc = [&](TreeNode* n) {
            if (!n) return 0LL;
            return n->val + calc(n->left) + calc(n->right);
        };
        total = calc(root);
        solve(root);
        return ans % MOD;
    }
};
