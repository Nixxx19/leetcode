class Solution {
public:
    void dfs(TreeNode* node, set<int>& s) {
        if (!node) return;
        s.insert(node->val);
        dfs(node->left, s);
        dfs(node->right, s);
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root, s);
        if (s.size() < 2) return -1;
        auto it = s.begin();
        it++;
        return *it;
    }
};
