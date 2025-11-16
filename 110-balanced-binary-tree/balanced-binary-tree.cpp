class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        unordered_map<TreeNode*, int> h;
        stack<TreeNode*> st;
        TreeNode* last = nullptr;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node->left && h.find(node->left) == h.end())
                st.push(node->left);
            else if (node->right && h.find(node->right) == h.end())
                st.push(node->right);
            else {
                st.pop();
                int l = node->left ? h[node->left] : 0;
                int r = node->right ? h[node->right] : 0;
                if (abs(l - r) > 1) return false;
                h[node] = max(l, r) + 1;
            }
        }
        return true;
    }
};
