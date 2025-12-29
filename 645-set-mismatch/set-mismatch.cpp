class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int d = 0, m = 0;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) d = abs(nums[i]);
            else nums[idx] = -nums[idx];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) m = i + 1;
        }
        return {d, m};
    }
};
