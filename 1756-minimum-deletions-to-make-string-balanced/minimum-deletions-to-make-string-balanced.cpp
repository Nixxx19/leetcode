class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> sufA(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            sufA[i] = sufA[i + 1] + (s[i] == 'a');

        int b = 0, ans = n;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, b + sufA[i]);
            if (i < n && s[i] == 'b') b++;
        }
        return ans;
    }
};
