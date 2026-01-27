class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(2 * n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            g[u + n].push_back({v + n, w});
            g[v].push_back({u + n, 2 * w});
            g[v + n].push_back({u + n, 2 * w});
        }

        const long long INF = 1e18;
        vector<long long> dist(2 * n, INF);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto &[v, w] : g[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        long long ans = min(dist[n - 1], dist[n - 1 + n]);
        return ans >= INF ? -1 : (int)ans;
    }
};
