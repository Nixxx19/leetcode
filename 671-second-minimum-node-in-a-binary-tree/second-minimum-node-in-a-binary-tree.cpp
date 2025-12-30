class Solution {
public:
    int helper(TreeNode* node, int base) {
        if (!node) return -1;
        if (node->val > base) return node->val;

        int l = helper(node->left, base);
        int r = helper(node->right, base);

        if (l == -1) return r;
        if (r == -1) return l;
        return min(l, r);
    }

    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }
};
