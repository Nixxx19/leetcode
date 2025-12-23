class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> cnt;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            cnt[node->val]++;
            dfs(node->right);
        };
        dfs(root);

        int mx = 0;
        for (auto &p : cnt) mx = max(mx, p.second);

        vector<int> res;
        for (auto &p : cnt)
            if (p.second == mx) res.push_back(p.first);
        return res;
    }
};
