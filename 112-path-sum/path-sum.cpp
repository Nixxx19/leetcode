class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        while (!st.empty()) {
            auto [node, sum] = st.top(); st.pop();
            if (!node->left && !node->right && sum == targetSum) return true;
            if (node->right) st.push({node->right, sum + node->right->val});
            if (node->left) st.push({node->left, sum + node->left->val});
        }
        return false;
    }
};
