class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = -1e5 , localMaxi = -1e5 ; 
        for(auto&it : nums ){
            localMaxi = max(localMaxi+it , it); 
            maxi = max(localMaxi ,maxi ); 
        }
        return maxi; 
    }
};