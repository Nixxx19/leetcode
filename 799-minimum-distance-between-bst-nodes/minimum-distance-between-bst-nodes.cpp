class Solution {
public:
    vector<int> v;

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for (int i = 1; i < v.size(); i++)
            ans = min(ans, v[i] - v[i - 1]);
        return ans;
    }
};
