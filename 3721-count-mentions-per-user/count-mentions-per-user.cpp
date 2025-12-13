class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        int N = events.size();
        vector<int> ts(N);
        for (int i = 0; i < N; i++) ts[i] = atoi(events[i][1].c_str());

        vector<int> m(n), on(n,1), off(n);
        vector<int> idx(N);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return ts[a] < ts[b];
        });

        int i = 0;
        while (i < N) {
            int t = ts[idx[i]];
            for (int u = 0; u < n; u++)
                if (!on[u] && off[u] <= t) on[u] = 1;

            int j = i;
            vector<int> offIdx, msgIdx;
            while (j < N && ts[idx[j]] == t) {
                if (events[idx[j]][0] == "OFFLINE") offIdx.push_back(idx[j]);
                else msgIdx.push_back(idx[j]);
                j++;
            }

            for (int k : offIdx) {
                int u = atoi(events[k][2].c_str());
                on[u] = 0;
                off[u] = t + 60;
            }

            for (int k : msgIdx) {
                string &s = events[k][2];
                if (s == "ALL") {
                    for (int u = 0; u < n; u++) m[u]++;
                } else if (s == "HERE") {
                    for (int u = 0; u < n; u++) if (on[u]) m[u]++;
                } else {
                    string tok;
                    stringstream ss(s);
                    while (ss >> tok)
                        m[atoi(tok.substr(2).c_str())]++;
                }
            }

            i = j;
        }

        return m;
    }
};
