class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, j = 1;
        while (j < nums.size()) {
            if (nums[j] != nums[k - 1])
                nums[k++] = nums[j];
            j++;
        }
        return k;
    }
};
