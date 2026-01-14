class Solution {
public:
    vector<vector<int>> dp;
    string s1, s2;
    map<pair<int,int>, set<string>> memo;

    set<string> backtrack(int i, int j) {
        if (i == 0 || j == 0)
            return {""};

        if (memo.count({i, j}))
            return memo[{i, j}];

        set<string> result;

        if (s1[i-1] == s2[j-1]) {
            set<string> prev = backtrack(i-1, j-1);
            for (auto &str : prev)
                result.insert(str + s1[i-1]);
        } else {
            if (dp[i-1][j] == dp[i][j]) {
                auto up = backtrack(i-1, j);
                result.insert(up.begin(), up.end());
            }
            if (dp[i][j-1] == dp[i][j]) {
                auto left = backtrack(i, j-1);
                result.insert(left.begin(), left.end());
            }
        }

        return memo[{i, j}] = result;
    }

    vector<string> allLCS(string &a, string &b) {
        s1 = a;
        s2 = b;
        int n = s1.size(), m = s2.size();

        dp.assign(n+1, vector<int>(m+1, 0));

        // Build LCS length DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        set<string> ans = backtrack(n, m);
        return vector<string>(ans.begin(), ans.end());
    }
};
