class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n = fruits.size();
        if (n == 0) return 0;
        return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) - 2 * fruits[n-1][n-1];
    }

private:
    int getTopLeft(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        long long res = 0;
        for (int i = 0; i < n; ++i) res += fruits[i][i];
        return (int)res;
    }

    int getTopRight(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][n-1] = fruits[0][n-1];

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                
                if (x >= y && !(x == n-1 && y == n-1)) continue;

                
                const vector<pair<int,int>> dirs = {{1,-1},{1,0},{1,1}};
                for (auto [dx,dy] : dirs) {
                    int i = x - dx;
                    int j = y - dy;
                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    
                    if (i < j && j < n - 1 - i) continue;
                    if (dp[i][j] == INT_MIN) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n-1][n-1] == INT_MIN ? 0 : dp[n-1][n-1];
    }

    int getBottomLeft(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[n-1][0] = fruits[n-1][0];

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                
                if (x <= y && !(x == n-1 && y == n-1)) continue;

                const vector<pair<int,int>> dirs = {{-1,1},{0,1},{1,1}};
                for (auto [dx,dy] : dirs) {
                    int i = x - dx;
                    int j = y - dy;
                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    
                    if (j < i && i < n - 1 - j) continue;
                    if (dp[i][j] == INT_MIN) continue;
                    dp[x][y] = max(dp[x][y], dp[i][j] + fruits[x][y]);
                }
            }
        }
        return dp[n-1][n-1] == INT_MIN ? 0 : dp[n-1][n-1];
    }
};
