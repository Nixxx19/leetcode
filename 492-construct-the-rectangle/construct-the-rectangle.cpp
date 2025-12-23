class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = area, w = 1;
        for (int i = 1; i <= sqrt(area); i++) {
            if (area % i == 0) {
                int j = area / i;
                if (j >= i) {
                    l = j;
                    w = i;
                }
            }
        }
        return {l, w};
    }
};
