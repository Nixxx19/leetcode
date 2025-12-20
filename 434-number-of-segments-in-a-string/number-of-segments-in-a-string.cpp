class Solution {
public:
    int countSegments(string s) {
        bool in = false;
        int c = 0;
        for (char ch : s) {
            if (ch != ' ') {
                if (!in) c++;
                in = true;
            } else in = false;
        }
        return c;
    }
};
