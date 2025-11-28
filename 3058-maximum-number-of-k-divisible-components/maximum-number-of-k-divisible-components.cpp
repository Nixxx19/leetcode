class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        function<long long(int,int)> dfs = [&](int u, int p) {
            long long cur = values[u];
            for (int v : g[u]) {
                if (v == p) continue;
                long long child = dfs(v, u);
                child %= k;
                if (child == 0) ans++;
                else cur += child;
            }
            return cur;
        };

        long long r = dfs(0, -1) % k;
        if (r == 0) ans++;
        return ans;
    }
};
