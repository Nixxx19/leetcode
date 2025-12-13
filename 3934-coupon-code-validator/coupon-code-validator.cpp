class Solution {
public:
    vector<string> validateCoupons(vector<string>& c,
                                   vector<string>& b,
                                   vector<bool>& a) {
        map<string,int> m={{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
        vector<pair<int,string>> v;
        for(int i=0;i<c.size();i++){
            if(!a[i]||!m.count(b[i])||c[i].empty()) continue;
            for(char x:c[i]) if(!isalnum(x)&&x!='_') goto bad;
            v.push_back({m[b[i]],c[i]});
            bad:;
        }
        sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.first==b.first?a.second<b.second:a.first<b.first;
        });
        vector<string> r;
        for(auto&p:v) r.push_back(p.second);
        return r;
    }
};
