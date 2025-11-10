class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0;
        int ans = 0;
        for (int x : nums) {
            if (x == 0) {
                if (left * 2 == total) ans += 2;
                else if (abs(left * 2 - total) == 1) ans += 1;
            }
            left += x;
        }
        return ans;
    }
};
