class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), 0);
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        nums.insert(nums.end(), cnt, 0);
    }
};
