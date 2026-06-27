class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (auto n : nums) mp[n]++;

        int best = 1;
        if (mp.count(1)) best = mp[1] % 2 ? mp[1] : mp[1] - 1;

        for (auto& p : mp) {
            long long x = p.first;
            if (x == 1) continue;

            int t = 0;
            while (mp.find(x) != mp.end() && mp[x] >= 2) {
                t += 2;
                x *= x;
            }
            if (mp.find(x) != mp.end()) t += 1;   // top exists -> peak
            else t -= 1;                          // borrow a pair as the peak
            best = max(best, t);
        }
        return best;
    }
};