class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>ans; 
        int prefix =0 ; 
        for(int i = 0 ; i< n ;i++ ){
            prefix = (prefix*2 + nums[i])%5;
            if( prefix % 5 == 0  ) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans; 
    }
};