class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<vector<int>> H(5), M(7);
        for (int i = 0; i < 12; i++) H[__builtin_popcount(i)].push_back(i);
        for (int i = 0; i < 60; i++) M[__builtin_popcount(i)].push_back(i);

        vector<string> ans;
        for (int i = 0; i <= turnedOn; i++) {
            if (i >= H.size() || turnedOn - i >= M.size()) continue;
            for (int h : H[i])
                for (int m : M[turnedOn - i]) {
                    string s = to_string(h) + ":";
                    if (m < 10) s += "0";
                    s += to_string(m);
                    ans.push_back(s);
                }
        }
        return ans;
    }
};
