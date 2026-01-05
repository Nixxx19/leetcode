class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> cnt, l, r;
        for (int i = 0; i < nums.size(); i++) {
            if (!l.count(nums[i])) l[nums[i]] = i;
            r[nums[i]] = i;
            cnt[nums[i]]++;
        }
        int deg = 0, ans = nums.size();
        for (auto &p : cnt) deg = max(deg, p.second);
        for (auto &p : cnt)
            if (p.second == deg)
                ans = min(ans, r[p.first] - l[p.first] + 1);
        return ans;
    }
};
