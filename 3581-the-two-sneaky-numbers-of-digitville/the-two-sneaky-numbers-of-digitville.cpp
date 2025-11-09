class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<int> res;
        for (auto& [k, v] : freq)
            if (v == 2) res.push_back(k);
        return res;
    }
};
