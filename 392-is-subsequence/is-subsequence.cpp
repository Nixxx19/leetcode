class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < t.size(); i++)
            pos[t[i]-'a'].push_back(i);

        int curr = -1;

        for (char c : s) {
            auto &v = pos[c - 'a'];
            auto it = upper_bound(v.begin(), v.end(), curr);
            if (it == v.end()) return false;
            curr = *it;
        }

        return true;
    }
};
