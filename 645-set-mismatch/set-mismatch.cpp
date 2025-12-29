class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int d = 0, m = 0;

        for (int x : nums) {
            if (!s.insert(x).second) d = x;
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (!s.count(i)) m = i;
        }

        return {d, m};
    }
};