class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> preN(n + 1, 0), sufY(n + 1, 0);

        for (int i = 0; i < n; i++)
            preN[i + 1] = preN[i] + (customers[i] == 'N');

        for (int i = n - 1; i >= 0; i--)
            sufY[i] = sufY[i + 1] + (customers[i] == 'Y');

        int ans = 0, best = INT_MAX;
        for (int j = 0; j <= n; j++) {
            int penalty = preN[j] + sufY[j];
            if (penalty < best) {
                best = penalty;
                ans = j;
            }
        }
        return ans;
    }
};
