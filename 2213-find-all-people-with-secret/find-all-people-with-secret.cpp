class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        };

        unite(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int m = meetings.size();
        int i = 0;

        while (i < m) {
            int time = meetings[i][2];
            vector<int> people;

            int j = i;
            while (j < m && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                people.push_back(meetings[j][0]);
                people.push_back(meetings[j][1]);
                j++;
            }

            for (int p : people) {
                if (find(p) != find(0))
                    parent[p] = p;
            }

            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                ans.push_back(i);
        }

        return ans;
    }
};
