class Solution {
public:
    int arrangeCoins(int n) {
        int r = 0;
        while (n >= r + 1) {
            r++;
            n -= r;
        }
        return r;
    }
};
