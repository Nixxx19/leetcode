class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0, temp = n;
        while (temp) { bits++; temp >>= 1; }
        int all1 = (1 << bits) - 1;
        if (n <= all1) return all1;
        return (1 << (bits + 1)) - 1;
    }
};
