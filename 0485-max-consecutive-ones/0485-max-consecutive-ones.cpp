class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0 ; 
        int count = 0 ; 
        for(auto& it : nums){
            if( it ==  1 ) count++ ; 
            else{
                maxi = max( maxi , count ); 
                count = 0 ; 
            }
        }
        maxi = max( maxi , count ); 
        return maxi ; 
    }
};