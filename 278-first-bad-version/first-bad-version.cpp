class Solution {
public:
    int solve(int l, int r) {
        if (l == r) return l;
        int m = l + (r - l) / 2;
        if (isBadVersion(m)) return solve(l, m);
        return solve(m + 1, r);
    }

    int firstBadVersion(int n) {
        return solve(1, n);
    }
};
