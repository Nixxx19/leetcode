class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int used = 0;
        for (int i = 0; i < s.size(); i++) {
            int w = widths[s[i] - 'a'];
            if (used + w <= 100) {
                used += w;
            } else {
                lines++;
                used = w;
            }
        }
        return {lines, used};
    }
};
