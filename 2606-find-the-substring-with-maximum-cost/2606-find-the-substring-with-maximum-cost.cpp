class Solution {
public:

    int solve(string& s, vector<int>&mp, vector<int>&dp, int i, int n, string& chars){

        if(i >= n) return 0;

        if(dp[i] != -1e7) return dp[i];

        int take = (chars.find(s[i]) != string::npos) 
                    ? mp[s[i]-'a'] 
                    : s[i]-'a'+1;

        int next = solve(s, mp, dp, i+1, n, chars);

        return dp[i] = max(take, take + next);
    }

    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();

        vector<int> dp(n, -1e7);
        vector<int> mp(26);

        for(int i = 0; i < vals.size(); i++){
            mp[chars[i]-'a'] = vals[i];
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, solve(s, mp, dp, i, n, chars));
        }

        return ans;
    }
};