class Solution {
public:
    int maxSubarrayLength(vector<int>& s, int k) {
        int left = 0 , right = 0 ; int maxi = 1; 
        unordered_map<int , int> mp ; 
        while( right < s.size() ){
            mp[s[right]]++; 

            while( left < s.size() and mp[s[right]] > k ){
                mp[s[left]]--; 
                left++; 
            }

            maxi = max( maxi , right-left+1 ); 
            right++; 
        }
        return maxi ; 
    }
};