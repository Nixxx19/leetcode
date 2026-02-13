class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> indices, res(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) indices.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(indices.begin(), indices.end(), i);
            int dist = 1e9;
            if (it != indices.end()) dist = min(dist, *it - i);
            if (it != indices.begin()) dist = min(dist, i - *prev(it));
            res[i] = dist;
        }
        return res;
    }
};