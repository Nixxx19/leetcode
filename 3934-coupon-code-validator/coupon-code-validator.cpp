class Solution {
public:
    int idx(string &s) {
        if (s=="electronics") return 0;
        if (s=="grocery") return 1;
        if (s=="pharmacy") return 2;
        if (s=="restaurant") return 3;
        return -1;
    }

    vector<string> validateCoupons(vector<string>& c,
                                   vector<string>& b,
                                   vector<bool>& a) {
        vector<pair<int,string>> v;
        for (int i=0;i<c.size();i++) {
            int k=idx(b[i]);
            if (k<0||!a[i]||c[i].empty()) continue;
            for (char x:c[i]) if (!isalnum(x)&&x!='_') goto bad;
            v.push_back({k,c[i]});
            bad:;
        }
        sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.first==b.first?a.second<b.second:a.first<b.first;
        });
        vector<string> r;
        for (auto&p:v) r.push_back(p.second);
        return r;
    }
};
