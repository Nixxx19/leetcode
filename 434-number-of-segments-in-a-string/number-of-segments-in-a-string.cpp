class Solution {
public:
    int countSegments(string s) {
        string t;
        stringstream ss(s);
        int c = 0;
        while (ss >> t) c++;
        return c;
    }
};
