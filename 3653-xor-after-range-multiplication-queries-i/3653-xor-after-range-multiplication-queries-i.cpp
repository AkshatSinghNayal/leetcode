class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(); 
        vector<long long> ans(nums.begin(),nums.end()); 
        int m  = queries.size();
        const int MOD = 1e9 + 7; 
        for(int i  = 0 ; i< m ; i++ ){
            int idx = queries[i][0]; 
            int ri = queries[i][1]; 
            int vi = queries[i][3];
            int ki = queries[i][2]; 
            while(idx<=ri){
                ans[idx]=((ans[idx]%MOD) * (vi%MOD)) % MOD;
                idx+=ki;
            }
        }
        int xorr = 0; 
        for(auto& it : ans ){
            xorr^=it;
        }
        return xorr; 

    }
};