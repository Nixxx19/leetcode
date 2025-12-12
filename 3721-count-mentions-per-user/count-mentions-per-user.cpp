class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        vector<int> m(n), on(n,1), off(n);
        sort(e.begin(), e.end(), [](auto&a,auto&b){return stoi(a[1])<stoi(b[1]);});
        int i=0, N=e.size();
        while (i<N) {
            int t=stoi(e[i][1]);
            for (int u=0;u<n;u++) if (!on[u] && off[u]<=t) on[u]=1;
            int j=i;
            vector<int> msgIdx, offIdx;
            while (j<N && stoi(e[j][1])==t) {
                if (e[j][0]=="OFFLINE") offIdx.push_back(j);
                else msgIdx.push_back(j);
                j++;
            }
            for (int k:offIdx) {
                int u=stoi(e[k][2]);
                on[u]=0; off[u]=t+60;
            }
            for (int k:msgIdx) {
                string s=e[k][2];
                if (s=="ALL") {
                    for (int u=0;u<n;u++) m[u]++;
                } else if (s=="HERE") {
                    for (int u=0;u<n;u++) if (on[u]) m[u]++;
                } else {
                    string tok; stringstream ss(s);
                    while (ss>>tok) m[stoi(tok.substr(2))]++;
                }
            }
            i=j;
        }
        return m;
    }
};
