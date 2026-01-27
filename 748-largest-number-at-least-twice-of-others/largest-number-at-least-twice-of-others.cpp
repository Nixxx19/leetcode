class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        pair<int,int> maxPair = {-1, -1}; // {value, index}
        int secondMax = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxPair.first) {
                secondMax = maxPair.first;
                maxPair = {nums[i], i};
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        return maxPair.first >= 2 * secondMax ? maxPair.second : -1;
    }
};
