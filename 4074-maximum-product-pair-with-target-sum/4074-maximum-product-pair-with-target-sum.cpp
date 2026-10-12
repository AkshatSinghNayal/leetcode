class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n  = nums.size(); 
        unordered_map<int,int>mp; 
        int maxi = INT_MIN, a =-1, b = -1; 
        for(int i  = 0 ;i<n ; i++ ){
            int needed = target - nums[i];
            // cout<< needed << " ";
            if( mp.count(needed) and needed!= nums[i]){
                if( maxi < needed*nums[i] ){
                    a=  (needed > nums[i]) ? mp[needed] : i; 
                    b=  ( a == mp[needed]) ? i : mp[needed]; 
                    maxi = max(maxi , needed*nums[i]); 
                }
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {a,b};
    }
};