class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        while (root) {
            if (root->left) {
                TreeNode* cur = root->left;
                while (cur->right && cur->right != root)
                    cur = cur->right;
                if (!cur->right) {
                    if (!root->left->left && !root->left->right)
                        sum += root->left->val;
                    cur->right = root;
                    root = root->left;
                } else {
                    cur->right = nullptr;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return sum;
    }
};
