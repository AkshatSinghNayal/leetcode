class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0 ; 
       
        int n=  nums.size() ; 
        for( int i = 0 ; i< nums.size() ; i++){
            int j = i ; 
            int sum  = 0; 
            while( j< n   ){
                sum+=nums[j]; 
                if(sum ==  k )count++; 
                j++; 

            }
            
        }
        return count ;
    }
};