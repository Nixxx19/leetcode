class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = nums[i] ? cur + 1 : 0;
            best = max(best, cur);
        }
        return best;
    }
};
