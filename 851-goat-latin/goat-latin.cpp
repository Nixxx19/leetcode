class Solution {
public:
    string toGoatLatin(string sentence) {
        string res;
        string_view sv = sentence;
        string vowels = "aeiouAEIOU";
        int idx = 1;
        size_t pos = 0, next;
        while ((next = sentence.find(' ', pos)) != string::npos || pos < sentence.size()) {
            string word = (next == string::npos) ? (string)sv.substr(pos) : (string)sv.substr(pos, next - pos);
            if (vowels.find(word[0]) == string::npos) rotate(word.begin(), word.begin() + 1, word.end());
            res += word + "ma" + string(idx++, 'a') + " ";
            if (next == string::npos) break;
            pos = next + 1;
        }
        if (!res.empty()) res.pop_back();
        return res;
    }
};