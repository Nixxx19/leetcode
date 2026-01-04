class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++) pos[nums[i]].push_back(i);
        int deg = 0, ans = nums.size();
        for (auto &p : pos) deg = max(deg, (int)p.second.size());
        for (auto &p : pos) {
            if (p.second.size() == deg) {
                ans = min(ans, p.second.back() - p.second.front() + 1);
            }
        }
        return ans;
    }
};
