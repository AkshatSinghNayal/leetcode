class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, -1); // store last seen index of each char
        int l = 0, maxLen = 0;
        for (int r = 0; r < s.size(); r++) {
            if (freq[s[r]] >= l) {
                l = freq[s[r]] + 1; // move left pointer past duplicate
            }
            freq[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
