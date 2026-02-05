class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int shift = nums[i];
            if (shift == 0) {
                res[i] = 0;
                continue;
            }
            shift = ((shift % n) + n) % n;
            res[i] = nums[(i + shift) % n];
        }
        return res;
    }
};
