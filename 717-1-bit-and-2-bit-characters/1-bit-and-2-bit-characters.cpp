class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = n - 2;
        while (i >= 0 && bits[i] == 1) i--;
        int ones = (n - 2) - i;
        return ones % 2 == 0;
    }
};
