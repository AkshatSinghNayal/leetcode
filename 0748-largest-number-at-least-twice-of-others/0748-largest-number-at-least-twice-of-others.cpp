class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index= max_element(nums.begin(),nums.end())-nums.begin();
        sort(nums.begin(),nums.end()) ; 
        int ans = INT_MIN ;
        int n  = nums.size() ; 
        int maxi = nums[n-1] ; 

        for( int i = n-2 ; i>= 0 ; i--){
            if( nums[i]*2 > maxi ){
                ans = -1 ; 
                break ;
            }
        }

        return ( ans == - 1) ? ans : index ; 


        
    }
};