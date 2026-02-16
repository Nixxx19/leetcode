class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0;
        for (char c : s) {
            if (c != '#') s[i++] = c;
            else if (i > 0) i--;
        }
        s.resize(i);
        
        i = 0;
        for (char c : t) {
            if (c != '#') t[i++] = c;
            else if (i > 0) i--;
        }
        t.resize(i);
        
        return s == t;
    }
};
