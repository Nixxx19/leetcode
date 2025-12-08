class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        queue<pair<TreeNode*,string>> q;
        q.push({root,to_string(root->val)});
        while (!q.empty()) {
            auto [n,s] = q.front(); q.pop();
            if (!n->left && !n->right) ans.push_back(s);
            if (n->left) q.push({n->left, s + "->" + to_string(n->left->val)});
            if (n->right) q.push({n->right, s + "->" + to_string(n->right->val)});
        }
        return ans;
    }
};
