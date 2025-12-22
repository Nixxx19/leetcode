class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int per = 0;
        int d[5] = {0, 1, 0, -1, 0};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + d[k], nj = j + d[k + 1];
                        if (ni < 0 || nj < 0 || ni >= r || nj >= c || grid[ni][nj] == 0)
                            per++;
                    }
                }
            }
        }
        return per;
    }
};
