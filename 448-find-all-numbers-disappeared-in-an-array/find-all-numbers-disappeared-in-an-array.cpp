class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);
        for (int x : nums) seen[x] = true;
        vector<int> res;
        for (int i = 1; i <= n; i++) if (!seen[i]) res.push_back(i);
        return res;
    }
};
