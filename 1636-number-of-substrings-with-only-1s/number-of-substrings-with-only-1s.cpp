class Solution {
public:
    int numSub(string s) {
        long long ans = 0, cur = 0, mod = 1e9 + 7;
        for (char c : s) {
            if (c == '1') cur++;
            else cur = 0;
            ans = (ans + cur) % mod;
        }
        return ans;
    }
};
