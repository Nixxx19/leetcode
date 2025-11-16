class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (!root->left || !root->right) return left + right + 1;
        return min(left, right) + 1;
    }
};
