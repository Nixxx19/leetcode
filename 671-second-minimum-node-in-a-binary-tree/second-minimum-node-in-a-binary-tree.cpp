class Solution {
public:
    long long ans = LLONG_MAX;
    int mn;

    void dfs(TreeNode* node) {
        if (!node) return;
        if (node->val > mn && node->val < ans) ans = node->val;
        dfs(node->left);
        dfs(node->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        mn = root->val;
        dfs(root);
        return ans == LLONG_MAX ? -1 : ans;
    }
};
