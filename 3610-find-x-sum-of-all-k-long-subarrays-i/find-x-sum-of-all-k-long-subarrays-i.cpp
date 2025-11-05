class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> f(51,0);
        for (int i = 0; i < k; i++) f[nums[i]]++;
        auto calc = [&]() {
            vector<pair<int,int>> v;
            for (int val = 1; val <= 50; val++) if (f[val]) v.push_back({f[val], val});
            sort(v.begin(), v.end(), [](auto &a, auto &b){
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int t = 0; t < (int)v.size() && t < x; t++) sum += v[t].first * v[t].second;
            return sum;
        };
        ans.push_back(calc());
        for (int i = k; i < n; i++) {
            f[nums[i-k]]--;
            f[nums[i]]++;
            ans.push_back(calc());
        }
        return ans;
    }
};
