class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0, maxi = 0;
        int n = s.size();
        for (int i = 0; (i < n and left < n); i++) {
            char ch = s[i];
            if (mp.count(ch) && mp[ch] >= left) {
                left = mp[ch] + 1;
            }
            mp[ch] = i;

            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};