class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1);
        int d = 0, m = 0;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) d = x;
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) m = i;
        }

        return {d, m};
    }
};
