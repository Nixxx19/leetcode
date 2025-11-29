class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long s = 0;
        for (int x : nums) s += x;
        return s % k;
    }
};
