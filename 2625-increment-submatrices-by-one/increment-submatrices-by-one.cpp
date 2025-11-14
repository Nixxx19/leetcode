class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n + 1, 0));

        for (auto &q : queries) {
            int r1 = q[0], c1 = q[1];
            int r2 = q[2], c2 = q[3];

            for (int r = r1; r <= r2; r++) {
                diff[r][c1]++;
                if (c2 + 1 < n) diff[r][c2 + 1]--;
            }
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                curr += diff[i][j];
                ans[i][j] = curr;
            }
        }

        return ans;
    }
};
