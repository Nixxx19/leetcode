class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string a = strs.front(), b = strs.back(), ans = "";
        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] == b[i]) ans += a[i];
            else break;
        }
        return ans;
    }
};
