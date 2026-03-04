class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size() ; 
        int maxi = INT_MIN;
        unordered_map<char , int > mp;
        int left = 0  , right = 0  ; 
        while( left < n and right < n ){
            char ch = s[right]; 
            mp[ch]++; 
            
            while( left < n and mp.size() > k ){
                mp[s[left]]--; 
                
                if( mp[s[left]] == 0  ){
                    mp.erase(s[left]); 
                }
                left++; 
            }
            
            if( mp.size() ==  k ) maxi = max( maxi , right -left +1 );  
            
            right++; 
        }
        
        return ( maxi == INT_MIN ) ? -1 : maxi ; 
    }
};