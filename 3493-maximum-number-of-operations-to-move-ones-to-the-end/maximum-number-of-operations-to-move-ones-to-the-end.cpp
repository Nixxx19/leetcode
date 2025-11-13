class Solution {
public:
    int maxOperations(string s) {
        long long ones = 0;
        long long ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else { // s[i] == '0'
                // start of a zero-block (either first char or previous was '1')
                if (i == 0 || s[i-1] == '1') {
                    ans += ones;
                }
            }
        }
        // ans is computed in 64-bit to avoid intermediate overflow.
        // The function signature asks for int; cast when returning.
        return static_cast<int>(ans);
    }
};
