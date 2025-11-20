class Solution
{
public:
    int titleToNumber(string s)
    {
        long long ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans += (s[i] - 'A' + 1) * pow(26, s.size()-1-i);
        return ans;
    }
};
