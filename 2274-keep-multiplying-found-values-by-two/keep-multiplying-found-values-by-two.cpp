class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> freq(2005);
        for (int x : nums) freq[x] = 1;
        while (freq[original]) original *= 2;
        return original;
    }
};
