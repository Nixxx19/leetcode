class Solution {
public:
    int arrangeCoins(long long n) {
        return (int)((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};
