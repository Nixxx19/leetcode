class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;
        for (char c : s)
            if (c != '-') t.push_back(toupper(c));

        int n = t.size();
        int first = n % k;
        string res;
        int i = 0;

        if (first) {
            res.append(t.substr(0, first));
            i = first;
            if (i < n) res.push_back('-');
        }

        while (i < n) {
            res.append(t.substr(i, k));
            i += k;
            if (i < n) res.push_back('-');
        }

        return res;
    }
};
