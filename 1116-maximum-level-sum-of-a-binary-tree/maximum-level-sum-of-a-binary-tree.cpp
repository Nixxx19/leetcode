class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, best = 1;
        long long bestSum = LLONG_MIN;
        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                auto n = q.front(); q.pop();
                sum += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            if (sum > bestSum) {
                bestSum = sum;
                best = level;
            }
            level++;
        }
        return best;
    }
};
