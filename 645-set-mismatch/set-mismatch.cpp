class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int d = 0, m = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) d = nums[i];
            else if (nums[i] > nums[i - 1] + 1) m = nums[i - 1] + 1;
        }

        if (nums.back() != nums.size()) m = nums.size();

        return {d, m};
    }
};
