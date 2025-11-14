class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = s.size() - 1;
        while (i >= 0) {
            if (s[i] == ' ' && len > 0) break;
            if (s[i] != ' ') len++;
            i--;
        }
        return len;
    }
};
