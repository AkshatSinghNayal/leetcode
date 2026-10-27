class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left =0 , right =0  , n = nums.size(); 
        unordered_map<int,int>mp;
        while(right<n){

            if(right-left>k) {
                    mp[nums[left]]--; 
                    if(mp[nums[left]] == 0 ) mp.erase(nums[left]); 
                    left++;
                }

            if( left < right and  right-left <= k ){
                if(mp.count(nums[right])) return true;
            }
            mp[nums[right]]++; 
            right++; 
        }
        return false;
    }
};