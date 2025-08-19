class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long zeros = 0;

        for (int num : nums) {
            if (num == 0) {
                zeros++;
            } 
            else {
                count += zeros * (zeros + 1) / 2;
                zeros = 0;
            }
        }
        
        count += zeros * (zeros + 1) / 2;

        return count;
    }
};