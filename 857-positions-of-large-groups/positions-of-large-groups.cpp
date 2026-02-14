class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size();
        int i = 0;

        while(i < n) {
            int start = i;

            while(i < n && s[i] == s[start]) {
                i++;
            }

            if(i - start >= 3) {
                ans.push_back({start, i - 1});
            }
        }

        return ans;
    }
};
