class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> ok(n - 1, 0);
        int ans = 0;
        for (int c = 0; c < m; c++) {
            bool bad = false;
            for (int i = 0; i < n - 1; i++) {
                if (!ok[i] && strs[i][c] > strs[i + 1][c]) {
                    bad = true;
                    break;
                }
            }
            if (bad) {
                ans++;
                continue;
            }
            for (int i = 0; i < n - 1; i++) {
                if (strs[i][c] < strs[i + 1][c]) ok[i] = 1;
            }
        }
        return ans;
    }
};
