class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp ;
        for ( int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        int ans; int check = 1; 
        for(auto it : mp ){
            if(it.second == 1 ){
                if(check ==1 ){
                    ans = it.first ; 
                    check++;
                }else{
                    return {ans , it.first};
                }
                
            }
        }
        return {0,0};
    }
};