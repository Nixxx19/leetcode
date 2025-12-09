class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), mod = 1000000007;
        int mx = 100000;
        vector<long long> left(mx+1), right(mx+1);
        for (int x : nums) right[x]++;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            right[x]--;
            int t = x * 2;
            if (t <= mx) ans = (ans + left[t] * right[t]) % mod;
            left[x]++;
        }
        return ans;
    }
};
