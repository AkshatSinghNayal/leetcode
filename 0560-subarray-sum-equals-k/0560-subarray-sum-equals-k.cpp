class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        int pre = 0 ; 
        mp[0]=  1 ; 
        int count= 0 ; 
        
        for( int i  = 0 ; i<nums.size() ; i++){
            pre += nums[i];
            int compliment =  (pre-k) ; 
            if(mp.count(compliment)){
                count+=mp[compliment]; 
            }
            mp[pre]++;
        }
        return count ; 
    }
};