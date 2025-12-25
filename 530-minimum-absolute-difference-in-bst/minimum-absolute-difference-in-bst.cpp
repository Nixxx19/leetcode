class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        int prev = -1, ans = INT_MAX;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if (prev != -1)
                ans = min(ans, cur->val - prev);
            prev = cur->val;
            cur = cur->right;
        }
        return ans;
    }
};
