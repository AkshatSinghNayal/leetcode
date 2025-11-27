class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int  n =  nums.size() ; 
        vector<long long> prefixSum(n); 
        prefixSum[0] = nums[0] ; 
        for( int i = 1  ; i< n ;i++){
            prefixSum[i]  = prefixSum[i-1]+nums[i] ; 
        }

        long long maxi =  LLONG_MIN ; 
        for( int i = 0 ; i < k  ; i++ ){
            long long sum = 0  ; 
            int index = i ; 
            while( index < n && index+k-1 < n ){
                int j =  index+k-1 ;
                long long subarrSum =  prefixSum[j] - ((index>0) ? prefixSum[index-1] : 0) ; 
                 sum =  max(subarrSum, sum + subarrSum);
                maxi = max( sum , maxi ) ; 
                index+=k ;

            }

        }
        
        return maxi ; 

    }
};