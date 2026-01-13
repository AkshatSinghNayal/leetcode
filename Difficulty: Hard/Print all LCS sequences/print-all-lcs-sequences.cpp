class Solution {
  public:
    
    void tabulation(string  &s1, string &s2, vector<vector<int>> &dp){
        int n1 = s1.size();
        int n2 = s2.size();
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    
    void backtrackDP(string &s1, string &s2, int i, int j, vector<vector<int>> &dp, set<string> &ans, string temp, unordered_map<string, bool> &mpp){
        if(i==0 || j==0){
            reverse(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        
        string key = to_string(i) + "," + to_string(j) + "," + temp;
        
        // if current state is already found, terminating the function call
        if(mpp.find(key) != mpp.end()) return;
        
        // marking current state as visited
        mpp[key]= true;
        
        if(s1[i-1]==s2[j-1]){
            backtrackDP(s1, s2, i-1, j-1, dp, ans, temp+s1[i-1], mpp);
        }
        else{
            if(dp[i][j] == dp[i-1][j]){
                backtrackDP(s1, s2, i-1, j, dp, ans, temp, mpp);
            }
            if(dp[i][j] == dp[i][j-1]){
                backtrackDP(s1, s2, i, j-1, dp, ans, temp, mpp);
            }
        }
    }
  
    vector<string> allLCS(string s, string t) {
        // Code here
        int n1 = s.size();
        int n2 = t.size();
        
        int lcs = 0;
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        tabulation(s, t, dp);
        
        set<string> ansSet;
        string temp = "";
        
        unordered_map<string, bool> mpp;
        
        backtrackDP(s, t, n1, n2, dp, ansSet, temp, mpp);
        
        vector<string> ans(ansSet.begin(), ansSet.end());
        
        return ans;
        
    }
};