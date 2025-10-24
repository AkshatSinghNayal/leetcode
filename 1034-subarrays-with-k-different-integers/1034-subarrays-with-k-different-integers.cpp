class Solution {
public:

    int atMost( vector<int>& nums , int goal ){
        int left = 0 , right = 0 , count = 0 ; 
        unordered_map<int , int> mp ; 
        int n = nums.size() ;
        while(right<n){

            mp[nums[right]]++; 
            if(goal == 0 ) return 0; 
            while(mp.size()>goal){
                mp[nums[left]]--; 
                if(mp[nums[left]] == 0 ){
                    mp.erase(nums[left]);
                }
                left++; 
            }

            count+=right-left+1;
            
            right++;
        }
        return count; 
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};