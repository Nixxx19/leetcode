class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int i = 0, n = prices.size();
        while (i < n) {
            int j = i;
            while (j + 1 < n && prices[j] - prices[j + 1] == 1) j++;
            long long k = j - i + 1;
            ans += k * (k + 1) / 2;
            i = j + 1;
        }
        return ans;
    }
};
