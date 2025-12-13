class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        vector<int> m(n), on(n,1), off(n);
        sort(e.begin(), e.end(), [](auto&a,auto&b){
            return atoi(a[1].c_str()) < atoi(b[1].c_str());
        });

        for (int i = 0; i < e.size();) {
            int t = atoi(e[i][1].c_str());

            for (int u = 0; u < n; u++)
                if (!on[u] && off[u] <= t) on[u] = 1;

            int j = i;
            vector<int> a, b;
            while (j < e.size() && atoi(e[j][1].c_str()) == t) {
                (e[j][0] == "OFFLINE" ? a : b).push_back(j);
                j++;
            }

            for (int k : a) {
                int u = atoi(e[k][2].c_str());
                on[u] = 0;
                off[u] = t + 60;
            }

            for (int k : b) {
                string &s = e[k][2];
                if (s == "ALL") {
                    for (int u = 0; u < n; u++) m[u]++;
                } else if (s == "HERE") {
                    for (int u = 0; u < n; u++) if (on[u]) m[u]++;
                } else {
                    int x = -1;
                    for (char c : s) {
                        if (isdigit(c)) x = (x < 0 ? c - '0' : x * 10 + c - '0');
                        else if (x >= 0) { m[x]++; x = -1; }
                    }
                    if (x >= 0) m[x]++;
                }
            }
            i = j;
        }
        return m;
    }
};
