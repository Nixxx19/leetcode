class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));

        for (int i = 0; i < m; i++) {
            vector<vector<int>> ndp(n, vector<int>(k, 0));
            for (int j = 0; j < n; j++) {
                int v = grid[i][j] % k;
                if (i == 0 && j == 0) {
                    ndp[0][v] = 1;
                    continue;
                }
                if (i > 0) {
                    for (int r = 0; r < k; r++) {
                        if (dp[j][r]) {
                            ndp[j][(r + v) % k] = (ndp[j][(r + v) % k] + dp[j][r]) % MOD;
                        }
                    }
                }
                if (j > 0) {
                    for (int r = 0; r < k; r++) {
                        if (ndp[j-1][r]) {
                            ndp[j][(r + v) % k] = (ndp[j][(r + v) % k] + ndp[j-1][r]) % MOD;
                        }
                    }
                }
            }
            dp = ndp;
        }
        return dp[n-1][0];
    }
};
