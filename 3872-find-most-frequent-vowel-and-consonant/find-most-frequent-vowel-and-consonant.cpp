class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26];  // Array for 'a' to 'z'
        
        // Set all counts to 0
        for (int i = 0; i < 26; i++) {
            freq[i] = 0;
        }

        // Count each character
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int index = c - 'a';  // Get index from 0 to 25
            freq[index] = freq[index] + 1;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        // Check each letter
        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;

            // Check if it's a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                if (freq[i] > maxVowel) {
                    maxVowel = freq[i];
                }
            }
            // Else it's a consonant
            else {
                if (freq[i] > maxConsonant) {
                    maxConsonant = freq[i];
                }
            }
        }

        return maxVowel + maxConsonant;
    }
};