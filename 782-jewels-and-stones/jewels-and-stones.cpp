class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for (char c : jewels) mask |= 1LL << (c - 'A');
        int ans = 0;
        for (char c : stones)
            if (mask & (1LL << (c - 'A'))) ans++;
        return ans;
    }
};
