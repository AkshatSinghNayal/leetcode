class Solution {
public:
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {
        // 1. Reverse the whole string
        reverse(s, 0, s.size() - 1);

        int n = s.size();
        int i = 0, j = 0;
    int start = 0;
        // 2. Reverse each word and remove extra spaces in-place
        while (j < n) {
            // Skip spaces
            while (j < n && s[j] == ' ') j++;
            if (j >= n) break;

            // Start of word
            if (i != 0) s[i++] = ' '; // add one space if it's not the first word
             start = i;

            // Copy word
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];

            // Reverse the copied word
            reverse(s, start, i - 1);
        }

        // 3. Resize to new length without trailing spaces
        s.resize(i);
        return s;
    }
};
