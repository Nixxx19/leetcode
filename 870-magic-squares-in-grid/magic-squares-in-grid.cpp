class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        vector<int> seen(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9 || seen[v]) return false;
                seen[v] = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != 15) return false;
            if (g[r][c+i] + g[r+1][c+i] + g[r+2][c+i] != 15) return false;
        }

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != 15) return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != 15) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i + 2 < m; i++) {
            for (int j = 0; j + 2 < n; j++) {
                if (isMagic(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};
