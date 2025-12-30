class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long first = root->val, second = LLONG_MAX;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur->val > first && cur->val < second)
                second = cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        return second == LLONG_MAX ? -1 : second;
    }
};
