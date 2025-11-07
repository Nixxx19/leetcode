class Solution {
public:
    bool can(vector<long long>& power, int r, long long k, long long x) {
        int n = power.size();
        vector<long long> add(n, 0);
        long long sumAdd = 0;
        for (int i = 0; i < n; ++i) {
            if (i - r - 1 >= 0) sumAdd -= add[i - r - 1];
            long long cur = power[i] + sumAdd;
            if (cur < x) {
                long long need = x - cur;
                if (need > k) return false;
                k -= need;
                add[min(n - 1, i + r)] += need;
                sumAdd += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];
        vector<long long> power(n);
        for (int i = 0; i < n; ++i)
            power[i] = pref[min(n, i + r + 1)] - pref[max(0, i - r)];

        long long lo = 0, hi = 2e14, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (can(power, r, k, mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
