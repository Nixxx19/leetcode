class Solution {
public:
    vector<int> res;
    int cur = 0, best = 0;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);

        if (prev && prev->val == node->val) cur++;
        else cur = 1;

        if (cur > best) {
            best = cur;
            res.clear();
            res.push_back(node->val);
        } else if (cur == best) {
            res.push_back(node->val);
        }

        prev = node;
        inorder(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};
