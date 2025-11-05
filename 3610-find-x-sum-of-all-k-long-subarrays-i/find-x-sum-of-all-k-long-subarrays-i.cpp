class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> f(51,0);
        for (int i = 0; i < k; i++) f[nums[i]]++;
        auto calc = [&]() {
            vector<bool> used(51,false);
            int sum = 0;
            for (int c = 0; c < x; c++) {
                int bestVal = -1, bestCnt = 0;
                for (int val = 1; val <= 50; val++) {
                    if (used[val] || f[val]==0) continue;
                    if (f[val] > bestCnt || (f[val]==bestCnt && val > bestVal)) {
                        bestCnt = f[val]; bestVal = val;
                    }
                }
                if (bestVal == -1) break;
                used[bestVal] = true;
                sum += bestCnt * bestVal;
            }
            return sum;
        };
        ans.push_back(calc());
        for (int i = k; i < n; i++) {
            f[nums[i-k]]--;
            f[nums[i]]++;
            ans.push_back(calc());
        }
        return ans;
    }
};
