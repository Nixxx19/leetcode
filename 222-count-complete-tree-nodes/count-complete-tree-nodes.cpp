class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = 0, rh = 0;
        TreeNode* L = root->left;
        TreeNode* R = root->right;
        while (L) { lh++; L = L->left; }
        while (R) { rh++; R = R->right; }
        if (lh == rh) return (1 << (lh + 1)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
