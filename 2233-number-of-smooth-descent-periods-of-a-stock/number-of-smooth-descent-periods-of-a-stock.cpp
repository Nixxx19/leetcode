class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long r=0,c=0;
        for(int i=0;i<p.size();i++){
            c=(i&&p[i-1]-p[i]==1)?c+1:1;
            r+=c;
        }
        return r;
    }
};
