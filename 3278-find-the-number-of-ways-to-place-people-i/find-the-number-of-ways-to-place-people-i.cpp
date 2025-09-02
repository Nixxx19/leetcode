class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int pairCount = 0;

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (a == b) continue;

                int x1 = points[a][0], y1 = points[a][1];
                int x2 = points[b][0], y2 = points[b][1];

                if (x1 <= x2 && y1 >= y2) {
                    bool isValid = true;

                    for (int c = 0; c < n; c++) {
                        if (c == a || c == b) continue;

                        int x = points[c][0], y = points[c][1];
                        if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid) pairCount++;
                }
            }
        }

        return pairCount;
    }
};
