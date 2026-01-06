class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long> lvl;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            long long s = 0;
            for (int i = 0; i < sz; i++) {
                auto n = q.front(); q.pop();
                s += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            lvl.push_back(s);
        }
        int idx = 0;
        for (int i = 1; i < lvl.size(); i++)
            if (lvl[i] > lvl[idx]) idx = i;
        return idx + 1;
    }
};
