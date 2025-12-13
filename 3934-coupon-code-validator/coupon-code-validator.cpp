class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_map<string,int> ord = {
            {"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}
        };
        vector<pair<int,string>> v;
        for (int i=0;i<code.size();i++) {
            if (!isActive[i] || !ord.count(businessLine[i]) || code[i].empty()) continue;
            bool ok=true;
            for (char c:code[i]) if (!isalnum(c)&&c!='_') ok=false;
            if (ok) v.push_back({ord[businessLine[i]],code[i]});
        }
        sort(v.begin(),v.end(),[](auto&a,auto&b){
            return a.first==b.first?a.second<b.second:a.first<b.first;
        });
        vector<string> r;
        for (auto&p:v) r.push_back(p.second);
        return r;
    }
};
