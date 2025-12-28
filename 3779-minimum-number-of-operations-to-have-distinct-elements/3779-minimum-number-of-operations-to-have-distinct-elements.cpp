class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool dub = false ;
        unordered_map<int,int>mp ; 
        int n = nums.size(); int length; 
        for( int i =n-1 ;i>=0  ;i--){
            int digit = nums[i]; 
            mp[digit]++; 
            if( mp[digit] == 2 ) break; 
            length = n-i; 
        }

        int rem = n - length ; 
        return( rem+3 -1 )/3 ; 
    }
};