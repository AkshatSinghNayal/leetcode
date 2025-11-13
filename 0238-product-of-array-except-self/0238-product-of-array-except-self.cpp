class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n  = nums.size() ; 
       vector<int> preffix , suffix(n) ; 
       int product = 1; 
       for( auto &it : nums ){
            product*=it; 
            preffix.push_back( product ); 
       }  
      product = 1 ;
       for( int i  = n-1 ;  i>=0 ;i--){
            product *= nums[i]; 
            suffix[i] = product ; 
       }

        nums[0] = suffix[1]; 
        nums[n-1] = preffix[n-2];
        for( int i  = 1 ; i<n-1 ; i++){
            nums[i]= preffix[i-1]*suffix[i+1]; 
        }


       
       return nums;
    }
};