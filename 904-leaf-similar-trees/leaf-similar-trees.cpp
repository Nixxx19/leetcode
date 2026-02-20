class Solution {
public:
    void collect(TreeNode* root, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right)
            leaves.push_back(root->val);
        collect(root->left, leaves);
        collect(root->right, leaves);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        collect(root1, a);
        collect(root2, b);
        return a == b;
    }
};
