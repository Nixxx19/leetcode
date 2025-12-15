class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> w;
        string t;
        stringstream ss(s);
        while (ss >> t) w.push_back(t);
        if (p.size() != w.size()) return false;

        unordered_map<string,char> mp;
        set<char> used;

        for (int i = 0; i < p.size(); i++) {
            if (mp.count(w[i])) {
                if (mp[w[i]] != p[i]) return false;
            } else {
                if (used.count(p[i])) return false;
                mp[w[i]] = p[i];
                used.insert(p[i]);
            }
        }
        return true;
    }
};
