class Solution {
public:
    int balancedString(string s) {
        int n  = s.size(); 
        int needed = n/4 , ans= INT_MAX; 
        unordered_map<char,int>mp;
        for(auto& it : s ) mp[it]++; 

        int left = 0 , right = 0; 
        while( right < n ){
            char ele = s[right]; 
            mp[ele]--; 
            while( left <n and mp['Q']<= needed and mp['W'] <= needed and mp['E'] <= needed and mp['R'] <= needed ){
                ans = min( right-left+1 , ans );
                mp[s[left]]++;
                left++; 
            }
            right++; 
        }
        
        
        return ans;
    }
};