class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> w;
        string t;
        stringstream ss(s);
        while (ss >> t) w.push_back(t);
        if (p.size() != w.size()) return false;

        unordered_map<char,string> m1;
        unordered_map<string,char> m2;

        for (int i = 0; i < p.size(); i++) {
            if (m1.count(p[i]) && m1[p[i]] != w[i]) return false;
            if (m2.count(w[i]) && m2[w[i]] != p[i]) return false;
            m1[p[i]] = w[i];
            m2[w[i]] = p[i];
        }
        return true;
    }
};
