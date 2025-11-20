class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int ans = 0;
        for (int b = 0; b < 32; b++)
        {
            int c = 0;
            for (int v : nums)
                if (v >> b & 1) c++;
            if (c > nums.size()/2)
                ans |= (1 << b);
        }
        return ans;
    }
};
