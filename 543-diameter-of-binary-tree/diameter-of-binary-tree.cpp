class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        int height = max(L.first, R.first) + 1;
        int diameter = max({L.second, R.second, L.first + R.first});

        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).second;
    }
};
