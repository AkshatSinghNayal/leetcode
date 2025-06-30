class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int result = 0;
        int i = 0;
        while (i < s.size()) {
            if (mp[s[i]] >= mp[s[i+1]]) {
                result += mp[s[i]];

            } else {
                if (i + 1 <= s.size() - 1) {

                    result += mp[s[i + 1]] - mp[s[i]];

                    i++;
                }
            }
            i++;
        }
        return result;
    }
};