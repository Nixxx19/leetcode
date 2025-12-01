class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int h = 0;
        TreeNode* node = root;
        while (node->left) {
            h++;
            node = node->left;
        }

        int left = 0, right = (1 << h) - 1;

        auto exists = [&](int idx, TreeNode* node) {
            int l = 0, r = (1 << h) - 1;
            for (int i = 0; i < h; i++) {
                int mid = (l + r) / 2;
                if (idx <= mid) {
                    node = node->left;
                    r = mid;
                } else {
                    node = node->right;
                    l = mid + 1;
                }
                if (!node) return false;
            }
            return true;
        };

        while (left <= right) {
            int mid = (left + right) / 2;
            if (exists(mid, root)) left = mid + 1;
            else right = mid - 1;
        }

        return (1 << h) - 1 + left;
    }
};
