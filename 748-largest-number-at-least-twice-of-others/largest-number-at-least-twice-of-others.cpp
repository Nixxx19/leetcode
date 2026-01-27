class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        int maxVal = *it;
        int idx = distance(nums.begin(), it);
        for (int i = 0; i < nums.size(); i++) {
            if (i != idx && maxVal < 2 * nums[i]) return -1;
        }
        return idx;
    }
};
