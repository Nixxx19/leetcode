class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            auto [node, sum] = q.front(); q.pop();
            if (!node->left && !node->right && sum == targetSum) return true;
            if (node->left) q.push({node->left, sum + node->left->val});
            if (node->right) q.push({node->right, sum + node->right->val});
        }
        return false;
    }
};
