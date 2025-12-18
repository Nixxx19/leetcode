class Solution {
public:
    bool isV(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isV(s[l])) l++;
            while (l < r && !isV(s[r])) r--;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};
