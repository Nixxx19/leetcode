class Solution {
public:
    string makeLargestSpecial(string s) {
        stack<vector<string>> st;
        st.push({});
        
        for (char c : s) {
            if (c == '1') {
                st.push({});
            } else {
                auto top = st.top();
                st.pop();
                
                sort(top.rbegin(), top.rend());
                
                string merged;
                for (auto &x : top) merged += x;
                
                string block = "1" + merged + "0";
                st.top().push_back(block);
            }
        }
        
        auto result = st.top();
        sort(result.rbegin(), result.rend());
        
        string ans;
        for (auto &x : result) ans += x;
        return ans;
    }
};
