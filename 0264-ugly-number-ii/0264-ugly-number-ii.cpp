class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 6) return n;

        vector<int> dp(n);  // store first n ugly numbers
        dp[0] = 1;          // first ugly number

        int i2 = 0, i3 = 0, i5 = 0; // pointers for multiples of 2,3,5

        for (int i = 1; i < n; i++) {
            int next = min({dp[i2]*2, dp[i3]*3, dp[i5]*5});
            dp[i] = next;

            if (next == dp[i2]*2) i2++;
            if (next == dp[i3]*3) i3++;
            if (next == dp[i5]*5) i5++;
        }

        return dp[n-1];
    }
};
