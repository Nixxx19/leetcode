class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> subs;

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + dfs(root->left) + dfs(root->right);
        subs.push_back(s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long best = 0;
        for (long long s : subs)
            best = max(best, s * (total - s));
        return best % MOD;
    }
};
