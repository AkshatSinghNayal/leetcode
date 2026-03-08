class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n  = nums.size(); 
        vector<vector<int>>ans;
        sort( nums.begin() , nums.end()) ; 
        for( int i  = 0  ; i < n ;i++ ){
            int j = i+1 ; 
            int k = n-1 ; 
            if( i > 0 and nums[i] ==  nums[i-1]) continue ; 
            int third = nums[i]; 
            while( j < k){
                int sum = nums[j]+nums[k]+third; 
                
                if( sum < 0 ){
                    j++;
                }
                else if( sum > 0 ){
                    k--;
                }
                else{
                    ans.push_back({third , nums[j] , nums[k]}); 
                    j++;k--;
                    while( j < n and nums[j] == nums[j-1]) j++; 
                    while( k>=0 and nums[k] == nums[k+1]) k--; 
                }
            }
            
        }
        return ans;
    }
};