class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int>mp; 
        int maxFreq = 0 ;
        for(auto& it : nums){
            mp[it]++; 
            maxFreq = max(maxFreq , mp[it]); 
        }

        mp.clear(); 

        int left = 0 , right = 0 , n = nums.size(); 
        int minLen = n+1;

        while(right < n ){
            int ele = nums[right]; 
            mp[ele]++; 
            while( mp[ele] == maxFreq ){
                mp[nums[left]]--; 
                minLen = min(minLen , right-left+1 ); 
                left++; 
            }

            right++; 
        }
        return minLen;
    }
};