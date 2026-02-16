class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static uint32_t table[256];
        static bool initialized = false;
        
        if (!initialized) {
            for (int i = 0; i < 256; i++) {
                uint32_t x = i, r = 0;
                for (int j = 0; j < 8; j++) {
                    r = (r << 1) | (x & 1);
                    x >>= 1;
                }
                table[i] = r;
            }
            initialized = true;
        }
        
        return (table[n & 0xff] << 24) |
               (table[(n >> 8) & 0xff] << 16) |
               (table[(n >> 16) & 0xff] << 8) |
               (table[(n >> 24) & 0xff]);
    }
};
