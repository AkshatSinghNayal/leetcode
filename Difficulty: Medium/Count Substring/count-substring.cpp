class Solution {
  public:
    int countSubstring(string s) {
        int n = s.size() ; 
        int left = 0 , right = 0 ; 
        vector<int> ans(3,0); 
            int count= 0; 
        while( right < n ){
            ans[s[right]-'a']++; 
            while( ans['a'-'a']>0 && ans['b'-'a']>0 && ans['c'-'a']>0 ){
                count+= (n-right); 
                ans[s[left]-'a']--; 
                left++; 
            }
            
            right++; 
            
        }
        return count; 
        
    }
};