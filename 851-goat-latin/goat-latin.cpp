class Solution {
public:
    string toGoatLatin(string sentence) {
        string res, word, vowels = "aeiouAEIOU";
        stringstream ss(sentence);
        int i = 0;
        while (ss >> word) {
            if (vowels.find(word[0]) == string::npos) {
                word = word.substr(1) + word[0];
            }
            res += (i > 0 ? " " : "") + word + "ma" + string(++i, 'a');
        }
        return res;
    }
};