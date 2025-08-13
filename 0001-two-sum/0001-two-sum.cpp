class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int > mp ; 
        for( int i = 0 ; i < nums.size() ; i++){
            if(mp.find(target - nums[i])!=mp.end()){
                   int ele = mp[target-nums[i]];
                   return {ele , i};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1} ; 
    }
};