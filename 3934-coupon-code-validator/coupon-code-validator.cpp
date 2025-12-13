class Solution {
public:
    vector<string> validateCoupons(vector<string>& c,
                                   vector<string>& b,
                                   vector<bool>& a) {
        struct X{int k; string s;};
        vector<X> v;
        for(int i=0;i<c.size();i++){
            int k=-1;
            if(b[i]=="electronics")k=0;
            else if(b[i]=="grocery")k=1;
            else if(b[i]=="pharmacy")k=2;
            else if(b[i]=="restaurant")k=3;
            if(k<0||!a[i]||c[i].empty()) continue;
            for(char x:c[i]) if(!isalnum(x)&&x!='_') goto bad;
            v.push_back({k,c[i]});
            bad:;
        }
        stable_sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.k==b.k?a.s<b.s:a.k<b.k;
        });
        vector<string> r;
        for(auto&x:v) r.push_back(x.s);
        return r;
    }
};
