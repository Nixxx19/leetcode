class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> cnt;
        for (int x : nums) cnt[x]++;

        long long ans = 1;
        for (auto& [v, c] : cnt) {
            if (v == 1) {                      // all ones, need odd length
                ans = max(ans, c - (c % 2 == 0));
                continue;
            }
            long long cur = v, len = 0;
            while (cnt.count(cur) && cnt[cur] >= 2) {
                len += 2;
                cur *= cur;
            }
            len += cnt.count(cur) ? 1 : -1;    // single peak, or give one back
            ans = max(ans, len);
        }
        return ans;
    }
};