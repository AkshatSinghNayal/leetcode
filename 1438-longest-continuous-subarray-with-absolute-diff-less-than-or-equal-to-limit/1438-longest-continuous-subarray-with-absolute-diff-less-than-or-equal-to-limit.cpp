class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left =0 , right = 0 , n = nums.size(); 
        multiset<pair<int,int>>mini;
        multiset<pair<int,int>,greater<pair<int,int>>>maxi;
        int maximum = INT_MIN;
        while(right<n){
            mini.insert({nums[right],right}); 
            maxi.insert({nums[right],right}); 

            while(left < right and abs( mini.begin()->first - maxi.begin()->first) > limit ){
                mini.erase({nums[left],left}); 
                maxi.erase({nums[left] , left}); 
                left++; 
            }   

            maximum = max(maximum , right-left+1 ); 

            right++;
        }
        return maximum ; 
    }
};