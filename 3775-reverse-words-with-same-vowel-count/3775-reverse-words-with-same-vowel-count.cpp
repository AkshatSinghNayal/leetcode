class Solution {
public:
    inline bool isVowel(char c) {
        return c == 'a' ||
               c == 'e' ||
               c == 'i' ||
               c == 'o' ||
               c == 'u';
    }

    void reverseStr(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        int count = 0, firstCount = 0;

        // Count vowels in the first word
        while (j < n && s[j] != ' ') {
            if (isVowel(s[j])) count++;
            j++;
        }
        firstCount = count;

        // Move to second word
        j++;
        i = j;

        // Process remaining words
        while (i < n && j < n) {
            count = 0;

            while (j < n && s[j] != ' ') {
                if (isVowel(s[j])) count++;
                j++;
            }

            if (count == firstCount) {
                reverseStr(s, i, j - 1);
            }

            j++;
            i = j;
        }

        return s;
    }
};
