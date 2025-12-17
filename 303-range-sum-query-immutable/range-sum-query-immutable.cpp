class NumArray {
public:
    vector<int> nums;

    NumArray(vector<int>& arr) {
        nums = arr;
    }

    int sumRange(int left, int right) {
        int s = 0;
        for (int i = left; i <= right; i++)
            s += nums[i];
        return s;
    }
};
