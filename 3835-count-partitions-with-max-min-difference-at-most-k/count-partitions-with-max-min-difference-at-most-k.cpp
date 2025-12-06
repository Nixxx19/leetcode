class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const int mod = 1e9 + 7;

        vector<long long> dp(n + 1), pref(n + 1);
        dp[0] = 1;
        pref[0] = 1;

        deque<int> mx, mn;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (!mx.empty() && nums[mx.back()] < nums[right]) mx.pop_back();
            mx.push_back(right);

            while (!mn.empty() && nums[mn.back()] > nums[right]) mn.pop_back();
            mn.push_back(right);

            while (nums[mx.front()] - nums[mn.front()] > k) {
                if (mx.front() == left) mx.pop_front();
                if (mn.front() == left) mn.pop_front();
                left++;
            }

            if (left == 0) {
                dp[right + 1] = pref[right] % mod;
            } else {
                dp[right + 1] = (pref[right] - pref[left - 1] + mod) % mod;
            }

            pref[right + 1] = (pref[right] + dp[right + 1]) % mod;
        }

        return dp[n];
    }
};
