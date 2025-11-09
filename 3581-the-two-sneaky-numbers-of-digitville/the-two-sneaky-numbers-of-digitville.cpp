class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0), res;
        for (int x : nums) freq[x]++;
        for (int i = 0; i < n; ++i)
            if (freq[i] == 2) res.push_back(i);
        return res;
    }
};
