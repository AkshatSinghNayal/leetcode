class Solution {
public:
    int numSub(string s) {

        s += '0';
        int count = 0;
        int ans =0;
        const int mod = 1e9+7;
        for (char c : s) {
            if (c == '0') {
                ans = (ans+ (count *1LL* (count + 1)) / 2)%mod;
                count=0;
            } else {
                count++;
            }
        }
        return ans;
    }
};