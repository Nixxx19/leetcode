class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> bit(2 * n + 2, 0);
        auto add = [&](int i) {
            for (++i; i <= 2 * n + 1; i += i & -i) bit[i]++;
        };
        auto query = [&](int i) {            // how many inserted are <= i
            int s = 0;
            for (++i; i > 0; i -= i & -i) s += bit[i];
            return s;
        };

        long long ans = 0;
        int pre = n;                 // P[0] = 0, shifted by n
        add(pre);
        for (int x : nums) {
            pre += (x == target) ? 1 : -1;
            ans += query(pre - 1);   // earlier prefixes strictly smaller
            add(pre);
        }
        return ans;
    }
};