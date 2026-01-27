class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n), rg(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            rg[e[1]].push_back({e[0], e[2]});
        }

        const long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(2, INF));
        priority_queue<array<long long,3>, vector<array<long long,3>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, mode] = pq.top();
            pq.pop();
            if (d != dist[u][mode]) continue;

            for (auto &[v, w] : g[u]) {
                if (dist[v][mode] > d + w) {
                    dist[v][mode] = d + w;
                    pq.push({dist[v][mode], v, mode});
                }
            }

            for (auto &[v, w] : rg[u]) {
                long long nd = d + 2LL * w;
                if (dist[v][1] > nd) {
                    dist[v][1] = nd;
                    pq.push({nd, v, 1});
                }
            }
        }

        long long ans = min(dist[n - 1][0], dist[n - 1][1]);
        return ans >= INF ? -1 : (int)ans;
    }
};
