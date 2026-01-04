class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> cnt, first, last;
        for (int i = 0; i < nums.size(); i++) {
            if (!first.count(nums[i])) first[nums[i]] = i;
            last[nums[i]] = i;
            cnt[nums[i]]++;
        }
        int deg = 0, ans = nums.size();
        for (auto &p : cnt) deg = max(deg, p.second);
        for (auto &p : cnt) {
            if (p.second == deg) {
                ans = min(ans, last[p.first] - first[p.first] + 1);
            }
        }
        return ans;
    }
};
