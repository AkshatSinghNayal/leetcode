class Solution {
public:
    string longestPalindrome(string text1) {
        string text2 = text1;
        reverse(text2.begin(), text2.end());

        int n = text1.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int maxi = 0;
        int end = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    int start1 = i - dp[i][j];

                    int start2 = n - j;

                    if (start1 == start2 && dp[i][j] > maxi) {
                        maxi = dp[i][j];
                        end = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return text1.substr(end - maxi, maxi);
    }
};