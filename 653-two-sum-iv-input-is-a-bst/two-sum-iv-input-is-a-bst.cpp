class Solution {
public:
    vector<int> v;

    void inorder(TreeNode* r) {
        if (!r) return;
        inorder(r->left);
        v.push_back(r->val);
        inorder(r->right);
    }

    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int s = v[l] + v[r];
            if (s == k) return true;
            if (s < k) l++;
            else r--;
        }
        return false;
    }
};