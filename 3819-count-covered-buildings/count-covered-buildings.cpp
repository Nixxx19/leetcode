class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        vector<int> xs, ys;
        xs.reserve(m);
        ys.reserve(m);
        for (auto &b : buildings) {
            xs.push_back(b[0]);
            ys.push_back(b[1]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int X = xs.size(), Y = ys.size();
        vector<vector<int>> row(X), col(Y);

        for (auto &b : buildings) {
            int cx = lower_bound(xs.begin(), xs.end(), b[0]) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), b[1]) - ys.begin();
            row[cx].push_back(cy);
            col[cy].push_back(cx);
        }

        for (auto &v : row) sort(v.begin(), v.end());
        for (auto &v : col) sort(v.begin(), v.end());

        int ans = 0;
        for (auto &b : buildings) {
            int cx = lower_bound(xs.begin(), xs.end(), b[0]) - xs.begin();
            int cy = lower_bound(ys.begin(), ys.end(), b[1]) - ys.begin();

            auto &r = row[cx];
            auto &c = col[cy];

            auto itR = lower_bound(r.begin(), r.end(), cy);
            bool left = itR != r.begin();
            bool right = itR + 1 != r.end();

            auto itC = lower_bound(c.begin(), c.end(), cx);
            bool up = itC != c.begin();
            bool down = itC + 1 != c.end();

            if (left && right && up && down) ans++;
        }
        return ans;
    }
};
