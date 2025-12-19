class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        int sum = 0;
        while (!st.empty()) {
            auto [node, isLeft] = st.top(); st.pop();
            if (!node->left && !node->right && isLeft)
                sum += node->val;
            if (node->right) st.push({node->right, false});
            if (node->left) st.push({node->left, true});
        }
        return sum;
    }
};
