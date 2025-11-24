class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size());
        long long val = 0;

        for (int i = 0; i < nums.size(); i++) {
            val = val * 2 + nums[i];
            val %= 5;
            ans[i] = (val == 0);
        }
        return ans;
    }
};
