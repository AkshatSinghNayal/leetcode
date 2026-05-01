class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size() , count =0; 
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefix = 0;
        for(int i  = 0 ;i< n; i++){
            int ele = nums[i]; 
            prefix = ((prefix+ele)%k +k)%k;
            if(mp.count(prefix)){
                count+=mp[prefix]; 
            }
            mp[prefix]++; 
        }
        return count;
    }
};