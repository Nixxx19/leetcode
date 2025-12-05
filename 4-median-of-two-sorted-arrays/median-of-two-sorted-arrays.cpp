class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);
        int m = A.size(), n = B.size();
        int l = 0, r = m;
        while (l <= r) {
            int i = (l + r) / 2;
            int j = (m + n + 1) / 2 - i;
            int L1 = i == 0 ? INT_MIN : A[i-1];
            int R1 = i == m ? INT_MAX : A[i];
            int L2 = j == 0 ? INT_MIN : B[j-1];
            int R2 = j == n ? INT_MAX : B[j];
            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2) return max(L1, L2);
                return (max(L1, L2) + min(R1, R2)) * 0.5;
            }
            if (L1 > R2) r = i - 1;
            else l = i + 1;
        }
        return 0;
    }
};
