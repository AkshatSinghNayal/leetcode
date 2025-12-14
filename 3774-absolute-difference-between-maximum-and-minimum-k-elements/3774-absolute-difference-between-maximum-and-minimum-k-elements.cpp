class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int add = 0 , sub= 0 ; 
        sort( nums.begin() , nums.end()); 
        int n  = nums.size() ; 

        for( int  i  = 0 ;  i< k ; i++){
            add+=nums[i]; 
        }
        for( int i = n -1 ; (i>=0 && k!=0) ; i--){
            sub+=nums[i]; 
            k--; 
        }
        return abs( add-sub ) ; 

    }
};