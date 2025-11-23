class Solution {
public:
    int longestPalindrome(string&s) {
        unordered_map<char,int> mpp;
        for(char x:s)mpp[x]++;
           int ans = 0;
    bool hasOdd = false;

    for (auto it : mpp) {
        if (it.second % 2 == 0) {
            ans += it.second;
        } else {
            ans += it.second - 1;
            hasOdd = true;
        }
    }

    if (hasOdd)
        ans += 1;

    return ans;
}
};