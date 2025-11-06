class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1), sz(c + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return;
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        };

        for (auto &e : connections) unite(e[0], e[1]);

        // Priority queue per component (min-heap)
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> pq;
        for (int i = 1; i <= c; ++i) pq[find(i)].push(i);

        vector<bool> online(c + 1, true);
        vector<int> ans;

        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);

            if (type == 1) {
                if (online[x]) ans.push_back(x);
                else {
                    // Lazy removal of offline nodes
                    while (!pq[root].empty() && !online[pq[root].top()])
                        pq[root].pop();

                    if (pq[root].empty()) ans.push_back(-1);
                    else ans.push_back(pq[root].top());
                }
            } else {
                online[x] = false;
            }
        }
        return ans;
    }
};
