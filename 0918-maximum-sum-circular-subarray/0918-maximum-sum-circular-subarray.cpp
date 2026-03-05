#include <bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], bestMax = nums[0] , bestMin = nums[0] , minSum = nums[0] , ans = nums[0] ;
        int n = nums.size(); 
        int i = 1 ; 
        int total = accumulate( nums.begin() , nums.end() , 0 ) ; 

        while( i < n ){
            bestMax = max( bestMax + nums[i] , nums[i] ); 
            maxSum = max( maxSum , bestMax );

            bestMin = min(bestMin+nums[i] , nums[i]); 
            minSum = min( minSum , bestMin );
            i++; 
        }

        if(maxSum<0){
            return maxSum ; 
        }

        ans = max( maxSum , total - minSum); 
        return ans ; 
    }
};