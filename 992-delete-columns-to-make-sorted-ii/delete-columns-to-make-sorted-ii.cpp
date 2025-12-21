class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<int> locked(n - 1, 0);
        int ans = 0;
        for (int j = 0; j < m; j++) {
            bool remove = false;
            for (int i = 0; i < n - 1; i++) {
                if (!locked[i] && strs[i][j] > strs[i + 1][j]) {
                    remove = true;
                    break;
                }
            }
            if (remove) {
                ans++;
            } else {
                for (int i = 0; i < n - 1; i++) {
                    if (strs[i][j] < strs[i + 1][j]) locked[i] = 1;
                }
            }
        }
        return ans;
    }
};
