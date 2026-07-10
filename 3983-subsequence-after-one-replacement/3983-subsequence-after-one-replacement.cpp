class Solution {
public:
    bool canMakeSubsequence(const string& s, const string& t) {
        int m = s.size();
        int slowPtr = 0, fastPtr = 0;

        for(char c : t) {
            if(c == s[fastPtr]) {
                fastPtr++;
            }

            fastPtr = max(fastPtr, slowPtr + 1);

            if(c == s[slowPtr]) {
                slowPtr++;
            }

            if(slowPtr == m || fastPtr == m) {
                return true;
            }
        }

        return false;
    }
};