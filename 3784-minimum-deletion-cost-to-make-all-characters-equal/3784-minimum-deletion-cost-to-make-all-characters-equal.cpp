class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n  =  s.size() ; 
        unordered_map<char,long long> mp ; 
        for( int i  = 0 ; i< n ; i++){
            char temp = s[i]; 
            mp[temp] = mp[temp]+cost[i]; 
        }
        long long maxi  = LLONG_MIN ; 
        char final;
        for( auto& it : mp ){
             if( maxi < it.second ){
                maxi = it.second ; 
                final = it.first ; 
             }
        }
        
        
        long long totalCost = 0 ; 
        for( auto& it : mp ){
            if(maxi != it.second or it.first!=final ) totalCost+=it.second; 
        }
        return totalCost ; 
    }
};