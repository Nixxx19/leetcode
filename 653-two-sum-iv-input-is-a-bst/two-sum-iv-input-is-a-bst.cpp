class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto n = q.front(); q.pop();
            if (s.count(k - n->val)) return true;
            s.insert(n->val);
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        return false;
    }
};