class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),
             [](auto &a, auto &b){ return a[1] < b[1]; });

        int n = events.size();
        vector<int> ends(n), best(n);
        for (int i = 0; i < n; i++) {
            ends[i] = events[i][1];
            best[i] = max((i ? best[i-1] : 0), events[i][2]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int s = events[i][0];
            int v = events[i][2];
            int j = lower_bound(ends.begin(), ends.end(), s) - ends.begin() - 1;
            if (j >= 0) ans = max(ans, v + best[j]);
            ans = max(ans, v);
        }
        return ans;
    }
};
