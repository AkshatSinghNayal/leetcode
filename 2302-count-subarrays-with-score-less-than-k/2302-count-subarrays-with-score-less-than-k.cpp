////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans= 0; 
        long long len =0;
        long long sum= 0; 
        int left = 0 , n = nums.size() , right = 0 ;

        while( right < n ) {

            sum+=nums[right]; 
            

            while(  left < right and (sum * 1LL * (right - left + 1) >= k)){
                sum-=nums[left];
                left++; 
            }


            if( sum<k and  sum*1LL*(right-left+1) < k ){
                ans+=( right-left+1);
            }

            right++; 
        }
        return ans;
    }
};