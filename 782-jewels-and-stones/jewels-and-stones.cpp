class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool isJewel[128] = {};
        for (char c : jewels) isJewel[c] = true;
        int ans = 0;
        for (char c : stones) if (isJewel[c]) ans++;
        return ans;
    }
};
