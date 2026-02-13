class Solution {
public:
    string toGoatLatin(string sentence) {
        string res, vowels = "aeiouAEIOU";
        int count = 0, n = sentence.length();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && sentence[j] != ' ') j++;
            string word = sentence.substr(i, j - i);
            if (vowels.find(word[0]) == string::npos) {
                word = word.substr(1) + word[0];
            }
            res += word + "ma" + string(++count, 'a') + (j < n ? " " : "");
            i = j;
        }
        return res;
    }
};