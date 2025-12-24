class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return score[a] > score[b];
        });

        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) res[idx[i]] = "Gold Medal";
            else if (i == 1) res[idx[i]] = "Silver Medal";
            else if (i == 2) res[idx[i]] = "Bronze Medal";
            else res[idx[i]] = to_string(i + 1);
        }
        return res;
    }
};
