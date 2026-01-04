class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int cnt = 0, sum = 0;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    cnt++;
                    sum += d;
                    if (d * d != x) {
                        cnt++;
                        sum += x / d;
                    }
                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};
