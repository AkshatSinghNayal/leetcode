class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n) ; 
        int even = 0 ; 
        int odd = n-1 ; 

        for( int i = 0 ;i<n ; i++){
            if( nums[i] % 2 == 0  ){
                ans[even] = nums[i] ; 
                even+=1;
            }
            else{
                ans[odd] = nums[i]; 
                odd-=1; 
            }
        }
return ans;
    }
};