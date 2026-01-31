class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int cnt[26] = {};
        for (char c : letters) cnt[c - 'a']++;
        for (int i = target - 'a' + 1; i < 26; i++)
            if (cnt[i]) return char('a' + i);
        for (int i = 0; i <= target - 'a'; i++)
            if (cnt[i]) return char('a' + i);
        return letters[0];
    }
};
