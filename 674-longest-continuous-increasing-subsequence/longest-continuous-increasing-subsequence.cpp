class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) cur++;
            else cur = 1;
            ans = max(ans, cur);
        }
        return ans;
    }
};
