class Solution {
public:
    int numSub(string s) {
        long long r = 0, c = 0, mod = 1e9+7;
        for (char x : s) r = (r + (x=='1' ? ++c : c=0)) % mod;
        return r;
    }
};
