class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                int i = l + 1, j = r;
                while (i < j && s[i] == s[j]) i++, j--;
                if (i >= j) return true;

                i = l; j = r - 1;
                while (i < j && s[i] == s[j]) i++, j--;
                return i >= j;
            }
            l++; r--;
        }
        return true;
    }
};
