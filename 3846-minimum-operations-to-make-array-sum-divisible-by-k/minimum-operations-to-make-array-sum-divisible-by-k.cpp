class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        return s % k;
    }
};
