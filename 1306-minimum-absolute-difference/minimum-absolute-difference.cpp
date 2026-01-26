class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        int d = INT_MAX;
        for (auto it = next(s.begin()); it != s.end(); it++)
            d = min(d, *it - *prev(it));
        vector<vector<int>> res;
        for (auto it = next(s.begin()); it != s.end(); it++)
            if (*it - *prev(it) == d)
                res.push_back({*prev(it), *it});
        return res;
    }
};
