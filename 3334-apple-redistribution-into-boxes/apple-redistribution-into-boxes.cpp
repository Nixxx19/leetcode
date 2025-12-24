class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int need = accumulate(apple.begin(), apple.end(), 0);
        vector<int> cnt(51, 0);
        for (int c : capacity) cnt[c]++;

        int used = 0;
        for (int c = 50; c >= 1 && need > 0; c--) {
            while (cnt[c]-- > 0 && need > 0) {
                need -= c;
                used++;
            }
        }
        return used;
    }
};
