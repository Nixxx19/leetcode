class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long totalSubarrays = 0;
        long long consecutiveZeros = 0;

        for (int val : nums) 
        {
            if (val == 0) 
            {
                consecutiveZeros++;
            } else 
            {
                totalSubarrays += consecutiveZeros * (consecutiveZeros + 1) / 2;
                consecutiveZeros = 0;
            }
        }

        totalSubarrays += consecutiveZeros * (consecutiveZeros + 1) / 2;

        return totalSubarrays;
    }
};
