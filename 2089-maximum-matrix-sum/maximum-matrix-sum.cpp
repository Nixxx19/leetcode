class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> v;
        int neg = 0;
        for (auto &r : matrix) {
            for (int x : r) {
                if (x < 0) neg++;
                v.push_back(abs(x));
            }
        }
        sort(v.begin(), v.end());
        long long sum = 0;
        for (int x : v) sum += x;
        if (neg % 2) sum -= 2LL * v[0];
        return sum;
    }
};
