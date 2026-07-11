class Solution {
public:

    bool solve( int i , string& s , unordered_map<char,vector<string>>&mp , vector<int>&dp  ){
        // base
        if( i >= s.size() ) return true; 

        if(dp[i] != -1 ) return dp[i] ; 

        char ch = s[i]; 

        for(auto& temp : mp[ch]){
            int k  = i; 
            int j = 0; 
            while( j<temp.size() and s[k] == temp[j]){
                j++; k++; 
            }

            if( j == temp.size()){
                if(solve( k , s , mp , dp )) return dp[i] = true; 
            }
        }
        
        return dp[i] = false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char,vector<string>>mp; 
        for(auto& it : wordDict ){
            mp[it[0]].push_back(it); 
        }

        vector<int>dp(s.size() , -1); 
        return solve(0,s,mp,dp); 
    }
};