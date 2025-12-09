class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), mod = 1000000007;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        vector<long long> left(n), right(n);
        for (int x : nums) {
            int i = lower_bound(v.begin(), v.end(), x) - v.begin();
            right[i]++;
        }
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            int id = lower_bound(v.begin(), v.end(), x) - v.begin();
            right[id]--;
            int t = x * 2;
            int p = lower_bound(v.begin(), v.end(), t) - v.begin();
            if (p < n && v[p] == t) ans = (ans + left[p] * right[p]) % mod;
            left[id]++;
        }
        return ans;
    }
};
