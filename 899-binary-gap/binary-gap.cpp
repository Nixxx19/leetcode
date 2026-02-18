class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, res = 0;
        
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                if (prev != -1)
                    res = max(res, i - prev);
                prev = i;
            }
        }
        
        return res;
    }
};
