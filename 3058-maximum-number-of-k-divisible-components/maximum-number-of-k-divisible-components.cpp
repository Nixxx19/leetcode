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
            long long s = values[u];
            for (int v : g[u]) {
                if (v == p) continue;
                long long r = dfs(v, u);
                if (r % k == 0) ans++;
                else s += r;
            }
            return s;
        };

        long long total = dfs(0, -1);
        if (total % k == 0) ans++;
        return ans;
    }
};