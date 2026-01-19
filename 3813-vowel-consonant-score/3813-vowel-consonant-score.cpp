class Solution {
public:
    int vowelConsonantScore(string s) {
        
        int vowel = 0, consonant = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                if (c == 'a' || c == 'e' || c == 'i' ||
                    c == 'o' || c == 'u') {
                    vowel++;
                } else {
                    consonant++;
                }
            }
        }

        return consonant > 0 ? vowel / consonant : 0;
    }
};