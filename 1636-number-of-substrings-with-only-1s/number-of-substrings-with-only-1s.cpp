class Solution {
public:
    int numSub(string s) {
        long long ans = 0, mod = 1e9 + 7;
        int n = s.size(), i = 0;
        while (i < n) {
            if (s[i] == '0') { i++; continue; }
            int j = i;
            while (j < n && s[j] == '1') j++;
            long long len = j - i;
            ans = (ans + len * (len + 1) / 2) % mod;
            i = j;
        }
        return ans;
    }
};
