class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        string vowels = "aeiou";
        int maxVowel = 0, maxConsonant = 0;

        for (char c : s) {
            freq[c]++;
        }

        for (auto& [ch, count] : freq) {
            if (vowels.find(ch) != string::npos) {
                maxVowel = max(maxVowel, count);
            } else {
                maxConsonant = max(maxConsonant, count);
            }
        }

        return maxVowel + maxConsonant;
    }
};