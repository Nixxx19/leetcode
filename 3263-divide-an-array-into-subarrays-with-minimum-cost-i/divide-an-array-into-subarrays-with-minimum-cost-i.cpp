class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> v(nums.begin() + 1, nums.end());
        sort(v.begin(), v.end());
        return nums[0] + v[0] + v[1];
    }
};
