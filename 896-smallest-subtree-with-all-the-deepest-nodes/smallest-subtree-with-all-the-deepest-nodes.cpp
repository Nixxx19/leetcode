class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};
        auto L = dfs(root->left);
        auto R = dfs(root->right);
        if (L.first > R.first) return {L.first + 1, L.second};
        if (L.first < R.first) return {R.first + 1, R.second};
        return {L.first + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
