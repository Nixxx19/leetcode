class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // free rooms by index
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) free.push(i);

        // busy rooms: {end_time, room_index}
        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>> busy;

        vector<int> cnt(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;

            // free rooms that are done before start
            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                busy.push({end, room});
                cnt[room]++;
            } else {
                auto [t, room] = busy.top(); busy.pop();
                busy.push({t + duration, room});
                cnt[room]++;
            }
        }

        // find room with max meetings
        int ans = 0;
        for (int i = 1; i < n; i++)
            if (cnt[i] > cnt[ans]) ans = i;

        return ans;
    }
};
