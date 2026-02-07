class Solution {
public:
    int minimumDeletions(string s) {
        int keepB = 0, res = 0;
        for (char c : s) {
            if (c == 'b') keepB++;
            else res = min(res + 1, keepB);
        }
        return res;
    }
};
