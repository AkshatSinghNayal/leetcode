////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size(); 
        int maxi = INT_MIN; 
        int left = 0 , right = n-1 ; 

        while(left < right ){
            int len = right - left; 
            maxi = max( {min(nums[right], nums[left])* len , maxi}); 

            if( nums[right]> nums[left]){
                left++; 
            }
            else{
                right--; 
            }
        }
        return maxi;
    }
};