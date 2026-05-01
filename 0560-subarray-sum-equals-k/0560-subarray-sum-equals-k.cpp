class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp; 
        mp[0]=1; 
        long long prefix = 0; int count =0;

        for(auto& it : nums ){
            prefix+=it; 
            int complement = (prefix-k);
            if(mp.count(complement)){
                count+=mp[complement]; 
            }
            mp[prefix]++;
        }
        return count;
    }
};