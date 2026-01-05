class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        while (cur && cur->val != val) {
            cur = val < cur->val ? cur->left : cur->right;
        }
        return cur;
    }
};
