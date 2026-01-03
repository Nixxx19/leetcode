class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long a = 6; // all 3 colors diff
        long long b = 6; // 2 colors same

        for (int i = 2; i <= n; i++) {
            long long na = (a * 2 + b * 2) % MOD;
            long long nb = (a * 2 + b * 3) % MOD;
            a = na;
            b = nb;
        }

        return (a + b) % MOD;
    }
};
