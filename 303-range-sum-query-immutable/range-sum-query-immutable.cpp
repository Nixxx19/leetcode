class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.assign(4 * n, 0);
        build(1, 0, n - 1, nums);
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[idx] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(idx * 2, l, m, nums);
        build(idx * 2 + 1, m + 1, r, nums);
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        return query(idx * 2, l, m, ql, qr)
             + query(idx * 2 + 1, m + 1, r, ql, qr);
    }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};
