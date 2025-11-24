class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        // next[mod][bit]
        int nextMod[5][2];
        for (int m = 0; m < 5; m++) {
            nextMod[m][0] = (m * 2 + 0) % 5;
            nextMod[m][1] = (m * 2 + 1) % 5;
        }

        vector<bool> ans;
        int mod = 0;
        for (int b : nums) {
            mod = nextMod[mod][b];
            ans.push_back(mod == 0);
        }
        return ans;
    }
};
