class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> cnt, l;
        int ans = nums.size(), deg = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!l.count(nums[i])) l[nums[i]] = i;
            cnt[nums[i]]++;
            if (cnt[nums[i]] > deg) {
                deg = cnt[nums[i]];
                ans = i - l[nums[i]] + 1;
            } else if (cnt[nums[i]] == deg) {
                ans = min(ans, i - l[nums[i]] + 1);
            }
        }
        return ans;
    }
};
