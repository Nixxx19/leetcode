class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long s = 0;
        for (int x : nums) s += x;
        int r = s % k;
        int ops = 0;
        while (ops < r) ops++;
        return ops;
    }
};
