class Solution {
public:
    string longestPalindrome(string text1) {

        string text2 = text1;
        reverse(text2.begin(), text2.end());

        int n = text1.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        pair<int, int> index;

        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                int call = (text1[i - 1] == text2[j - 1]) ? 1 + dp[i - 1][j - 1] : 0;
                dp[i][j] = call;

                if (call) {

                    int start1 = i - call;
                    int start2 = n - j;

                    if (start1 == start2 && maxi < call) {
                        maxi = call;
                        index = {i - 1, j - 1};
                    }
                }
            }
        }

        if (maxi == 0) return "";

        return text1.substr(index.first - maxi + 1, maxi);
    }
};