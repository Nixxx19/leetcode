class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> w;
        string t;
        stringstream ss(s);
        while (ss >> t) w.push_back(t);
        if (p.size() != w.size()) return false;

        unordered_map<char,int> m1;
        unordered_map<string,int> m2;

        for (int i = 0; i < p.size(); i++) {
            if (m1[p[i]] != m2[w[i]]) return false;
            m1[p[i]] = m2[w[i]] = i + 1;
        }
        return true;
    }
};
