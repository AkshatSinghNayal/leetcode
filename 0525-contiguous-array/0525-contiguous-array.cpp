class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp ; 
        mp[0]=-1;
        int count0 = 0  , count1 = 0; int len = 0 ;
        for(int i  = 0 ;i< nums.size(); i++ ){
            if(nums[i]) count1++; 
            else count0++; 

            int needed  = count1 - count0; 

            if(mp.count(needed)){
                len = max(len , i - mp[needed]); 
            }
            else{
                mp[needed] = i;
            }

        }   
        return len;
    }
};