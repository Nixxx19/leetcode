class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n, -1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                res[i] = 0;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : {cur - 1, cur + 1}) {
                if (next >= 0 && next < n && res[next] == -1) {
                    res[next] = res[cur] + 1;
                    q.push(next);
                }
            }
        }
        return res;
    }
};