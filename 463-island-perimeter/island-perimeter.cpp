class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int d[5] = {0, 1, 0, -1, 0};

        function<int(int,int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0)
                return 1;
            if (vis[i][j]) return 0;
            vis[i][j] = 1;
            int res = 0;
            for (int k = 0; k < 4; k++)
                res += dfs(i + d[k], j + d[k + 1]);
            return res;
        };

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j])
                    return dfs(i, j);

        return 0;
    }
};
