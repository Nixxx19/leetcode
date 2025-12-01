class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (long long b : batteries) sum += b;
        long long left = 0, right = sum / n;

        while (left < right) {
            long long mid = (left + right + 1) / 2;
            long long need = mid * n;
            long long have = 0;
            for (long long b : batteries) have += min(b, mid);
            if (have >= need) left = mid;
            else right = mid - 1;
        }

        return left;
    }
};
