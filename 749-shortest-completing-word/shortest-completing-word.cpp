class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        for (char c : licensePlate) {
            if (isalpha(c)) cnt[tolower(c) - 'a']++;
        }

        string res;
        for (auto &word : words) {
            vector<int> wc(26, 0);
            for (char c : word) wc[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > wc[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok && (res.empty() || word.size() < res.size())) {
                res = word;
            }
        }
        return res;
    }
};
