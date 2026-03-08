#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 
        vector<long long> prefix(k+1 , LLONG_MAX);
        prefix[0] = 0; 
        long long currPrefix= 0  , ans = LLONG_MIN; 

        for( int i  = 0 ; i<n ;i++ ){
            currPrefix += nums[i]; 
            int mod = (  i+1)%k; 

            if( prefix[mod] != LLONG_MAX ){
                ans = max(ans , currPrefix - prefix[mod]);
            }

            prefix[mod] = min( prefix[mod] , currPrefix ); 

        }

        return ans;

    }
};