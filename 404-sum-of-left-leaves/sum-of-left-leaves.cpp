class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        int sum = 0;
        while (!q.empty()) {
            auto [node, isLeft] = q.front(); q.pop();
            if (!node->left && !node->right && isLeft)
                sum += node->val;
            if (node->left) q.push({node->left, true});
            if (node->right) q.push({node->right, false});
        }
        return sum;
    }
};
