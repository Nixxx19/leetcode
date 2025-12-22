class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0, best = 0;
        for (int x : nums) {
            if (x == 1) cur++;
            else cur = 0;
            best = max(best, cur);
        }
        return best;
    }
};
