class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n, 0));

        for (auto &q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                for (int j = q[1]; j <= q[3]; j++) {
                    mat[i][j]++;
                }
            }
        }

        return mat;
    }
};
