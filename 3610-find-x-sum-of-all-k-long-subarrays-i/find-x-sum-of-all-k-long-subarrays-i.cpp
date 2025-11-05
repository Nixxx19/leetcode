class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i + k <= n; i++) {
            vector<int> f(51,0);
            for (int j = i; j < i + k; j++) f[nums[j]]++;
            vector<pair<int,int>> v;
            for (int val = 1; val <= 50; val++) if (f[val]) v.push_back({f[val], val});
            sort(v.begin(), v.end(), [](auto &a, auto &b){
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int t = 0; t < (int)v.size() && t < x; t++) sum += v[t].first * v[t].second;
            ans.push_back(sum);
        }
        return ans;
    }
};
