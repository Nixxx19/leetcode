class Solution {
public:
    stack<TreeNode*> l, r;

    void pushLeft(TreeNode* n) {
        while (n) {
            l.push(n);
            n = n->left;
        }
    }

    void pushRight(TreeNode* n) {
        while (n) {
            r.push(n);
            n = n->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        pushLeft(root);
        pushRight(root);

        while (!l.empty() && !r.empty() && l.top() != r.top()) {
            int a = l.top()->val;
            int b = r.top()->val;
            if (a + b == k) return true;
            if (a + b < k) {
                TreeNode* n = l.top(); l.pop();
                pushLeft(n->right);
            } else {
                TreeNode* n = r.top(); r.pop();
                pushRight(n->left);
            }
        }
        return false;
    }
};