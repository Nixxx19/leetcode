class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        for (char c : licensePlate)
            if (isalpha(c)) cnt[tolower(c) - 'a']++;

        string res;
        int minLen = INT_MAX;

        vector<vector<int>> wordCounts;
        for (auto &word : words) {
            vector<int> wc(26,0);
            for (char c : word) wc[c - 'a']++;
            wordCounts.push_back(wc);
        }

        for (int i = 0; i < words.size(); i++) {
            bool ok = true;
            for (int j = 0; j < 26; j++)
                if (cnt[j] > wordCounts[i][j]) { ok = false; break; }
            if (ok && words[i].size() < minLen) {
                minLen = words[i].size();
                res = words[i];
            }
        }
        return res;
    }
};
