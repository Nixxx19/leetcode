class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) 
            {
                int j = i;
                while (j < nums.size() && nums[j] == 0) 
                {
                    count += (j - i + 1);  
                    j++;
                }
                i = j - 1;
            }
        }
        return count;
    }
};
