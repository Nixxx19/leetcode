class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -1e18;
        vector<long long> flat(k + 1, NEG), lon(k + 1, NEG), sho(k + 1, NEG);
        flat[0] = 0;

        for (int p : prices) {
            auto nf = flat, nl = lon, ns = sho;
            for (int t = 0; t <= k; t++) {
                if (flat[t] != NEG) {
                    nl[t] = max(nl[t], flat[t] - p);
                    ns[t] = max(ns[t], flat[t] + p);
                }
                if (t + 1 <= k && lon[t] != NEG)
                    nf[t + 1] = max(nf[t + 1], lon[t] + p);
                if (t + 1 <= k && sho[t] != NEG)
                    nf[t + 1] = max(nf[t + 1], sho[t] - p);
            }
            flat.swap(nf);
            lon.swap(nl);
            sho.swap(ns);
        }

        return *max_element(flat.begin(), flat.end());
    }
};
