class Solution {
public:
    vector<int> constructRectangle(int area) {
        int bestL = area, bestW = 1;
        for (int w = 1; w * w <= area; w++) {
            if (area % w == 0) {
                int l = area / w;
                if (l - w < bestL - bestW) {
                    bestL = l;
                    bestW = w;
                }
            }
        }
        return {bestL, bestW};
    }
};
