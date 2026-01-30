class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s(jewels.begin(), jewels.end());
        int ans = 0;
        for (char c : stones) if (s.count(c)) ans++;
        return ans;
    }
};
