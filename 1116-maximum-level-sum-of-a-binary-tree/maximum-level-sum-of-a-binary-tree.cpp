class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,long long> mp;
        int mx = 1;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* n, int d) {
            if (!n) return;
            mp[d] += n->val;
            mx = max(mx, d);
            dfs(n->left, d + 1);
            dfs(n->right, d + 1);
        };
        dfs(root, 1);
        long long best = LLONG_MIN;
        int ans = 1;
        for (int i = 1; i <= mx; i++) {
            if (mp[i] > best) {
                best = mp[i];
                ans = i;
            }
        }
        return ans;
    }
};
