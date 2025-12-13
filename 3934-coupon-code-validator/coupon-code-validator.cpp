class Solution {
public:
    vector<string> validateCoupons(vector<string>& c,
                                   vector<string>& b,
                                   vector<bool>& a) {
        vector<vector<string>> v(4);
        unordered_map<string,int> mp={
            {"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}
        };
        for (int i=0;i<c.size();i++) {
            if (!a[i]||!mp.count(b[i])||c[i].empty()) continue;
            bool ok=true;
            for (char x:c[i]) if(!isalnum(x)&&x!='_') ok=false;
            if (ok) v[mp[b[i]]].push_back(c[i]);
        }
        vector<string> r;
        for (int i=0;i<4;i++) {
            sort(v[i].begin(),v[i].end());
            for (auto&s:v[i]) r.push_back(s);
        }
        return r;
    }
};
