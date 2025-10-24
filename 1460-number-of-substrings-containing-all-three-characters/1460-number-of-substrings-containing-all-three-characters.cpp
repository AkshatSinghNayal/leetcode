class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() ; 
        unordered_map<char,int>mp(3); 
        int left = 0 , right = 0; 
        int count = 0 ; 
        while(right<n ){
            
            mp[s[right]]++; 
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                count+=(n-right);
                if(left+1 <n ){
                mp[s[left]]--;}
                    left++;
            }


            right++;
        }
        return count ; 
    }
};