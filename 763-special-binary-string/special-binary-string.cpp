class Solution {
public:
    string makeLargestSpecial(string s) {
        function<string(string)> solve = [&](string str) {
            vector<string> blocks;
            int bal = 0, start = 0;
            
            for (int i = 0; i < str.size(); i++) {
                bal += (str[i] == '1') ? 1 : -1;
                if (bal == 0) {
                    string inner = str.substr(start + 1, i - start - 1);
                    blocks.push_back("1" + solve(inner) + "0");
                    start = i + 1;
                }
            }
            
            sort(blocks.rbegin(), blocks.rend());
            
            string ans;
            for (auto &b : blocks) ans += b;
            return ans;
        };
        
        return solve(s);
    }
};
