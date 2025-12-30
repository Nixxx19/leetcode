class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        int l = 0;
        for (int r = 1; r < n; r++) {
            if (nums[r] <= nums[r - 1]) l = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
