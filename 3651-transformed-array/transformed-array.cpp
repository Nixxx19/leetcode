class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int cur = i;
            int steps = abs(nums[i]);
            if (nums[i] > 0) {
                while (steps--) cur = (cur + 1) % n;
            } else if (nums[i] < 0) {
                while (steps--) cur = (cur - 1 + n) % n;
            }
            res[i] = nums[i] == 0 ? 0 : nums[cur];
        }
        return res;
    }
};
