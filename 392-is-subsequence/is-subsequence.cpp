class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos = -1;
        for (char c : s) {
            pos = t.find(c, pos + 1);
            if (pos == string::npos) return false;
        }
        return true;
    }
};
