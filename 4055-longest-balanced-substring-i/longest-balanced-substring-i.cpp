class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;

            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if(freq[idx] == 0) distinct++;
                freq[idx]++;

                int len = j - i + 1;
                if(len % distinct == 0) {
                    int target = len / distinct;
                    bool ok = true;

                    for(int k = 0; k < 26; k++) {
                        if(freq[k] > 0 && freq[k] != target) {
                            ok = false;
                            break;
                        }
                    }

                    if(ok) ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
