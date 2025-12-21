class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), res = 0;
        vector<bool> fixed(n - 1, false);
        for (int j = 0; j < m; j++) {
            bool del = false;
            for (int i = 0; i < n - 1; i++) {
                if (!fixed[i] && strs[i][j] > strs[i + 1][j]) {
                    del = true;
                    break;
                }
            }
            if (del) {
                res++;
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (strs[i][j] < strs[i + 1][j]) fixed[i] = true;
                }
            }
        }
        return res;
    }
};
