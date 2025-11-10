class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                for (int dir : {-1, 1}) {
                    vector<int> arr = nums;
                    int curr = i, d = dir;
                    while (curr >= 0 && curr < n) {
                        if (arr[curr] == 0) curr += d;
                        else {
                            arr[curr]--;
                            d = -d;
                            curr += d;
                        }
                    }
                    if (all_of(arr.begin(), arr.end(), [](int x){ return x == 0; })) ans++;
                }
            }
        }
        return ans;
    }
};
