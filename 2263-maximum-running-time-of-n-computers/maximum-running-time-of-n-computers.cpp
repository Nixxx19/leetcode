class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for (long long b : batteries) total += b;

        long long lo = 0, hi = total / n;

        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long use = 0;
            for (long long b : batteries) {
                use += min(b, mid);
            }
            if (use >= mid * n) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};
