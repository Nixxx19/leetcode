class Solution {
public:
    unordered_map<int,int> dp;
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        if (dp.count(n)) return dp[n];
        int b = 0;
        while ((1 << (b + 1)) <= n) b++;
        return dp[n] = ((1 << (b + 1)) - 1) - minimumOneBitOperations(n ^ (1 << b));
    }
};
