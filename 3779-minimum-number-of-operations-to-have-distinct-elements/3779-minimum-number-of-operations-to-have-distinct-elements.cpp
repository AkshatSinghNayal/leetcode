class Solution {
public:
    int minOperations(vector<int>& nums) {
        int dubplicate = 0 , count = 0  ;
        int n = nums.size() ; 
        unordered_map<int,int> mp ; 
        for( auto &it : nums){
            mp[it]++; 
            if( mp[it] == 2 ) dubplicate++; 
        }
        if( dubplicate == 0 ) return  0 ; 

        int i = 0 ; 
        while( i < n ){
            for( int j = 0 ; j<3 and i< n ; i++, j++){
                if(mp[nums[i]] ==  2){
                    dubplicate--; 
                }
                mp[nums[i]]--; 
            }
            count++; 
            if( dubplicate == 0 ) break; 
        }
        return count ;
    }
};