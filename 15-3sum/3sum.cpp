class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        vector<int> vals;
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());
        vector<vector<int>> res;
        for (int i = 0; i < vals.size(); ++i)
            for (int j = i; j < vals.size(); ++j) {
                int a = vals[i], b = vals[j], c = -a - b;
                if (!freq.count(c)) continue;
                if (c < b) continue;
                if (a == b && b == c && freq[a] < 3) continue;
                if ((a == b && freq[a] < 2) || (b == c && freq[b] < 2) || (a == c && freq[a] < 2)) continue;
                res.push_back({a, b, c});
            }
        return res;
    }
};
