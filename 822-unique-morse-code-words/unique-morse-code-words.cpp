class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> st;
        for (auto &w : words) {
            string t;
            for (char c : w) t += morse[c - 'a'];
            st.insert(t);
        }
        return st.size();
    }
};
