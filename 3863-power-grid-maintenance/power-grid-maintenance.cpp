class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        vector<int> parent(c + 1), size(c + 1, 1);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        };
        
       
        for (auto &e : connections) unite(e[0], e[1]);

        unordered_map<int, set<int>> compOnline;
        for (int i = 1; i <= c; ++i)
            compOnline[find(i)].insert(i);

        vector<bool> online(c + 1, true);
        vector<int> result;
 
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = find(x);

            if (type == 1) {
                if (online[x]) result.push_back(x);
                else {
                    if (compOnline[root].empty()) result.push_back(-1);
                    else result.push_back(*compOnline[root].begin());
                }
            } else {
                if (online[x]) {
                    online[x] = false;
                    compOnline[root].erase(x);
                }
            }
        }

        return result;
    }
};
