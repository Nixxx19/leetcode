class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int widthUsed = 0;
        int i = 0;

        while(i < s.size()) {
            int w = widths[s[i] - 'a'];

            if(widthUsed + w > 100) {
                lines++;
                widthUsed = 0;
            } else {
                widthUsed += w;
                i++;
            }
        }

        return {lines, widthUsed};
    }
};
