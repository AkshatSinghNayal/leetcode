class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp ; 
        int i = 0;
        for(auto& it : nums){
            if(mp.count(target - it )){
                return { mp[target - it ] , i }; 
            }
            mp[it] = i; 
            i++; 
        }
        return {}; 
    }
};