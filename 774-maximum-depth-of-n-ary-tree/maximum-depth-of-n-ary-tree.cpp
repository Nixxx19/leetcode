class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            depth++;
            while (sz--) {
                Node* cur = q.front(); q.pop();
                for (Node* child : cur->children)
                    q.push(child);
            }
        }
        return depth;
    }
};
