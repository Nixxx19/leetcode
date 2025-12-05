class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int s = 0;
        for (int x : nums) s += x;
        if (s % 2) return 0;
        return nums.size() - 1;
    }
};
