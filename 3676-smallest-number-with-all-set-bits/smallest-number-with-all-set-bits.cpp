class Solution {
public:
    int smallestNumber(int n) {
        while (true) {
            int x = n, ok = 1;
            while (x) {
                if ((x & 1) == 0) { ok = 0; break; }
                x >>= 1;
            }
            if (ok) return n;
            n++;
        }
    }
};
