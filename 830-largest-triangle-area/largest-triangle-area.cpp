class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        double ans = 0;
        int n = p.size();

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                for(int k = j + 1; k < n; k++)
                    ans = max(ans, abs(
                        p[i][0]*(p[j][1]-p[k][1]) +
                        p[j][0]*(p[k][1]-p[i][1]) +
                        p[k][0]*(p[i][1]-p[j][1])
                    ) / 2.0);

        return ans;
    }
};
