class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp ; 
        for(auto& it : nums){
            mp[it]++; 
        }

        int n = nums.size(); 
        return ( mp[nums[n/2]] == 1 ) ? true : false ;
    }
};