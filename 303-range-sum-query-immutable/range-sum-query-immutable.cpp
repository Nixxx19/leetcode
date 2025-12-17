class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int>& arr) {
        nums = arr;
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
    }

    int sumRange(int left, int right) {
        if (left == 0) return nums[right];
        return nums[right] - nums[left - 1];
    }
};
