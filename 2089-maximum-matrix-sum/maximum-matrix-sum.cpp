class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long s = 0;
        int cnt = 0;
        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s += llabs(matrix[i][j]);
                if (matrix[i][j] < 0) cnt++;
                m = min(m, abs(matrix[i][j]));
            }
        }
        return cnt % 2 ? s - 2LL * m : s;
    }
};
