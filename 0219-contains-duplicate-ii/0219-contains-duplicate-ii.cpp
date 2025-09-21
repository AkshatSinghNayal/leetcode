class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        int left = 0 ; 
        int right = 0; 
        int i =0 ; 
        while(right<nums.size()){

            if( i>k ){
                mp[nums[left]]--; 
                left++;
                i--;
            }
            if(mp[nums[right]]>=1){
                return true; 
            }

            mp[nums[right]]++;
            i++; 
            right++; 
        }
        return false;
    }
};