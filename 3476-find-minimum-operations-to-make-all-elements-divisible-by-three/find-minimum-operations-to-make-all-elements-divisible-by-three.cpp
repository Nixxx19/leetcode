class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int x : nums) {
            if (x % 3 == 1) ops++;
            else if (x % 3 == 2) ops++;
        }
        return ops;
    }
};
