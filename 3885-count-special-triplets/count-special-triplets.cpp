class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long> left, right;
        long long ans = 0, mod = 1000000007;
        for (int x : nums) right[x]++;
        for (int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            right[x]--;
            long long t = x * 2;
            if (left.count(t) && right.count(t))
                ans = (ans + left[t] * right[t]) % mod;
            left[x]++;
        }
        return ans;
    }
};
