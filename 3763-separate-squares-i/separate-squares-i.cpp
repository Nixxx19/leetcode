class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        using ld = long double;

        vector<pair<ld, ld>> events; 
        ld totalArea = 0;

        for (auto& s : squares) {
            ld y = s[1];
            ld l = s[2];
            totalArea += l * l;
            events.push_back({y, +l});
            events.push_back({y + l, -l});
        }

        sort(events.begin(), events.end());

        ld target = totalArea / 2.0;
        ld currArea = 0;
        ld slope = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            ld y = events[i].first;
            slope += events[i].second;

            ld nextY = events[i + 1].first;
            if (slope == 0) continue;

            ld height = nextY - y;
            ld addArea = slope * height;

            if (currArea + addArea >= target) {
                ld needed = target - currArea;
                return (double)(y + needed / slope);
            }

            currArea += addArea;
        }

        return 0.0;
    }
};
