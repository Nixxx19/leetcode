#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    long long maxSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<long long> best(k, LLONG_MAX);

        long long prefix = 0;
        best[0] = 0; 

        long long ans = LLONG_MIN;

        for (int i = 0; i < n; ++i) 
        {
            prefix += nums[i];
            int r = (i + 1) % k;

            if (best[r] != LLONG_MAX) 
            {
                ans = max(ans, prefix - best[r]);
            }

            best[r] = min(best[r], prefix);
        }

        return ans;
    }
};
