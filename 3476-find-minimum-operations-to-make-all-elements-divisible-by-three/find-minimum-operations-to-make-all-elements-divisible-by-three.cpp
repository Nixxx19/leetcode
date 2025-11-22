class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int x : nums) ops += (x % 3 != 0);
        return ops;
    }
};
