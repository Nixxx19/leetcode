class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n);
        int prev = -n, next = s.find(c);
        for (int i = 0; i < n; ++i) {
            res[i] = min(i - prev, next - i);
            if (i == next) {
                prev = next;
                next = s.find(c, prev + 1);
                if (next == string::npos) next = 2 * n;
            }
        }
        return res;
    }
};