class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> pref(n + 1, vector<int>(26, 0));

        // prefix freq
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }

        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // check for each outer character
        for (int c = 0; c < 26; c++) {
            int L = first[c], R = last[c];
            if (L != -1 && R - L >= 2) {
                int count = 0;
                for (int mid = 0; mid < 26; mid++) {
                    if (pref[R][mid] - pref[L + 1][mid] > 0)
                        count++;
                }
                ans += count;
            }
        }
        return ans;
    }
};
