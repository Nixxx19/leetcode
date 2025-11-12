class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones) return n - ones;

        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            if (g == 1) return n - 1;
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        return (minLen == INT_MAX) ? -1 : (minLen - 1 + n - 1);
    }
};
