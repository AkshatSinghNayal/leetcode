class Solution {
  public:
    string text1, text2; // Need these as member variables
    
    set<string> backtracking(int n, int m, vector<vector<int>>& dp, 
                             map<pair<int,int>, set<string>>& memo) {
        // Base case
        if (n == 0 || m == 0) return {""};
        
        // Check memo
        if (memo.count({n, m})) {
            return memo[{n, m}];
        }
        
        set<string> result;
        
        // If characters match, prepend to all subsequences from (n-1, m-1)
        if (text1[n-1] == text2[m-1]) {
            set<string> prev = backtracking(n-1, m-1, dp, memo);
            for (const string& s : prev) {
                result.insert(s + text1[n-1]);
            }
        } 
        else {
            // If they don't match, explore both directions if they lead to LCS
            if (dp[n-1][m] == dp[n][m]) {
                set<string> left = backtracking(n-1, m, dp, memo);
                result.insert(left.begin(), left.end());
            }
            if (dp[n][m-1] == dp[n][m]) {
                set<string> up = backtracking(n, m-1, dp, memo);
                result.insert(up.begin(), up.end());
            }
        }
        
        memo[{n, m}] = result;
        return result;
    }
  
    vector<string> allLCS(string &s1, string &s2) {
        text1 = s1;
        text2 = s2;
        int n = text1.size(), m = text2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = (text1[i-1] == text2[j-1]) ? 
                           1 + dp[i-1][j-1] : 
                           max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        map<pair<int,int>, set<string>> memo;
        auto res = backtracking(n, m, dp, memo);
        return vector<string>(res.begin(), res.end());
    }
};