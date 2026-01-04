class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            char a = s[i];
            while (j < s.size() && s[j] == a) j++;
            int k = j;
            char b = a ^ 1;
            while (k < s.size() && s[k] == b) k++;
            ans += min(j - i, k - j);
            i = j - 1;
        }
        return ans;
    }
};
