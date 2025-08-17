class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int right = 0;
        int maxFreq = 0, maxLen = 0, windowSize = 0;
        while (right < s.size()) {

            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            windowSize = right - left + 1;
            while (windowSize - maxFreq > k) {
                freq[s[left] - 'A']--; // ⚡ fix index
                left++;
                // ⚡ recompute maxFreq from scratch (brute style)
                maxFreq = 0;
                for (int i = 0; i < 26; i++) {
                    maxFreq = max(maxFreq, freq[i]);
                }
                windowSize = right - left + 1;
            }

            maxLen = max(maxLen, right - left + 1);

            right++;
        }
        return maxLen;
    }
};