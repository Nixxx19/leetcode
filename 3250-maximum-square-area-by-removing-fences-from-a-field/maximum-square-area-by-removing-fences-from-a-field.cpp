class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1000000007;
        vector<long long> h, v;
        h.push_back(1);
        h.push_back(m);
        for (int x : hFences) h.push_back(x);
        v.push_back(1);
        v.push_back(n);
        for (int x : vFences) v.push_back(x);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        unordered_set<long long> hs;
        for (int i = 0; i < h.size(); i++)
            for (int j = i + 1; j < h.size(); j++)
                hs.insert(h[j] - h[i]);
        long long best = 0;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                long long d = v[j] - v[i];
                if (hs.count(d)) best = max(best, d);
            }
        }
        if (best == 0) return -1;
        return (best % MOD) * (best % MOD) % MOD;
    }
};