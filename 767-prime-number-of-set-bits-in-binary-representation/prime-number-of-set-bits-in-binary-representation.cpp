class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int mask = 0;
        for (int p : {2,3,5,7,11,13,17,19})
            mask |= (1 << p);

        int ans = 0;
        for (int i = left; i <= right; i++) {
            int c = __builtin_popcount(i);
            if (mask & (1 << c)) ans++;
        }
        return ans;
    }
};
