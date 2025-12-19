class Solution {
public:
    vector<string> ans;
    void dfs(int idx, int cnt, int h, int m, int k) {
        if (h >= 12 || m >= 60) return;
        if (cnt == k) {
            string s = to_string(h) + ":";
            if (m < 10) s += "0";
            s += to_string(m);
            ans.push_back(s);
            return;
        }
        if (idx == 10) return;
        if (idx < 4) dfs(idx + 1, cnt + 1, h | (1 << idx), m, k);
        else dfs(idx + 1, cnt + 1, h, m | (1 << (idx - 4)), k);
        dfs(idx + 1, cnt, h, m, k);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        dfs(0, 0, 0, 0, turnedOn);
        return ans;
    }
};
