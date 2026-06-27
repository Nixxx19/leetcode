class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + (nums[i] == target ? 1 : -1);
        vector<int> tmp(n + 1);
        return go(pre, tmp, 0, n);
    }
private:
    long long go(vector<int>& a, vector<int>& tmp, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = (lo + hi) >> 1;
        long long cnt = go(a, tmp, lo, mid) + go(a, tmp, mid + 1, hi);

        int i = lo, j = mid + 1;
        while (i <= mid && j <= hi) {            // left val < right val
            if (a[i] < a[j]) { cnt += hi - j + 1; i++; }
            else j++;
        }

        i = lo; j = mid + 1; int k = lo;         // standard merge
        while (i <= mid && j <= hi)
            tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
        while (i <= mid) tmp[k++] = a[i++];
        while (j <= hi)  tmp[k++] = a[j++];
        for (int t = lo; t <= hi; t++) a[t] = tmp[t];
        return cnt;
    }
};