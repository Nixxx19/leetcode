class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt[128] = {};
        for (char c : stones) cnt[c]++;
        int ans = 0;
        for (char c : jewels) ans += cnt[c];
        return ans;
    }
};
