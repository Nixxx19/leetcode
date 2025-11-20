class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int,int> m;
        for (int v : nums) m[v]++;
        int n = nums.size();
        for (auto& p : m)
            if (p.second > n/2) return p.first;
        return 0;
    }
};
