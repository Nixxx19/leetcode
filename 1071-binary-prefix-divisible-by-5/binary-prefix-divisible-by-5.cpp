class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        int r = 0;
        for (int b : nums) {
            r = ((r << 1) + b) % 5;
            res.push_back(r == 0);
        }
        return res;
    }
};
