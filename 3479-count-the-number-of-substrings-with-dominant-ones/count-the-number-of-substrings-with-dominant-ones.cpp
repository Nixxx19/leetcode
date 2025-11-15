class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = (int)s.size();
        vector<int> zeros;
        zeros.reserve(n);
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);

        long long ans = 0;

        // Count substrings with zero zeros (all-ones substrings)
        // i.e., contiguous segments of '1'
        long long run = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ++run;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;

        int m = (int)zeros.size();
        if (m == 0) {
            // All substrings already counted (all ones).
            return (int)ans;
        }

        // Maximum zeros to consider: z such that z^2 <= n
        int B = 0;
        while ((long long)(B+1) * (B+1) <= n) ++B;
        // iterate z from 1..B
        for (int z = 1; z <= B; ++z) {
            if (m < z) break;
            // sliding window on zeros positions: window of size z (zeros[i]..zeros[i+z-1])
            for (int i = 0; i + z - 1 < m; ++i) {
                int j = i + z - 1;
                int leftZero = zeros[i];
                int rightZero = zeros[j];
                int prevZeroPos = (i == 0 ? -1 : zeros[i-1]);
                int nextZeroPos = (j == m-1 ? n : zeros[j+1]);

                int leftGap = leftZero - prevZeroPos - 1;   // number of ones available on left expansion
                int rightGap = nextZeroPos - rightZero - 1; // number of ones available on right expansion

                int internalLen = rightZero - leftZero + 1;
                int internalOnes = internalLen - z; // ones between the covered zeros

                long long need = 1LL * z * z - internalOnes; // required extra ones from left+right
                if (need <= 0) {
                    // all choices of left/right extras valid
                    ans += 1LL * (leftGap + 1) * (rightGap + 1);
                    continue;
                }
                if (need > leftGap + rightGap) {
                    // can't reach required ones
                    continue;
                }

                // Count number of pairs (a, b) with 0<=a<=leftGap, 0<=b<=rightGap and a+b >= need
                // = totalPairs - countBad where countBad = pairs with a+b <= need-1
                long long totalPairs = 1LL * (leftGap + 1) * (rightGap + 1);
                long long k = need - 1; // sum upper bound for "bad" pairs

                // compute countBad efficiently
                long long L = leftGap;
                long long R = rightGap;
                long long countBad = 0;
                if (k < 0) {
                    countBad = 0;
                } else if (k >= L + R) {
                    countBad = totalPairs;
                } else {
                    // a from 0..L
                    // For a <= k-R => b_max = R => contributes (R+1)
                    // For a in [t1..t2] where t1 = max(0, k-R+1), t2 = min(L, k)
                    // contribution k - a + 1
                    long long t1 = max(0LL, k - R + 1); // first a where b_max < R
                    long long t2 = min(L, k);
                    if (t1 > 0) {
                        countBad += t1 * (R + 1);
                    }
                    if (t2 >= t1) {
                        long long cnt = (t2 - t1 + 1);
                        // sum_{a=t1..t2} (k - a + 1) = cnt*(k+1) - (sum a)
                        long long sumA = (t1 + t2) * cnt / 2;
                        countBad += cnt * (k + 1) - sumA;
                    }
                }

                long long valid = totalPairs - countBad;
                ans += valid;
            }
        }

        // ans fits within int for given constraints (n <= 4e4 -> n*(n+1)/2 < 2^31)
        return (int)ans;
    }
};