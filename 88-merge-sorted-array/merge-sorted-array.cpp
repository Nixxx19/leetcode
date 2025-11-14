#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.end(), merged.begin());
        for (int i = 0; i < m + n; i++) nums1[i] = merged[i];
    }
};
