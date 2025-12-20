class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp ; 
        int n  =  nums.size(); 
        int count = 0  ; 
        for( int i  = n-1 ; i>= 0 ; i--){
            mp[nums[i]]++; 
            if( mp[nums[i]]>1) break; // found dubplicate now we have to count the ele then ceil division ; 
            count++; 

        }
        int totalOperations = n - count ; 
        return( totalOperations + 2 ) / 3; 
    }
};