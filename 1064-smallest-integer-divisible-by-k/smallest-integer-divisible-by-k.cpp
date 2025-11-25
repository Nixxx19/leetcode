class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        unordered_set<int> seen;

        int rem = 0;
        for (int len = 1; len <= k + 5; len++) {
            rem = (rem * 10 + 1) % k;

            if (rem == 0) return len;
            if (seen.count(rem)) return -1; 

            seen.insert(rem);
        }
        return -1;
    }
};
