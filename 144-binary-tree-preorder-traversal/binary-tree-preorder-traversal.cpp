class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (!pre->right) {
                    res.push_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
