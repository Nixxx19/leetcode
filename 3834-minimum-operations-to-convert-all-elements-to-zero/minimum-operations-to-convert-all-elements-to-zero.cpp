class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        vector<int> v;
        v.push_back(0);
        for (int x : nums) {
            while (!v.empty() && v.back() > x)
                v.pop_back();
            if (v.empty() || v.back() < x) {
                ops++;
                v.push_back(x);
            }
        }
        return ops;
    }
};
