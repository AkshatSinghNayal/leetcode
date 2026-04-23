class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n  =  nums.size(); 
        long long suffix = accumulate( nums.begin() , nums.end() , 0LL);  
        long long prefix = 0 ; 
        vector<int>result(n,0); 
        for(int i  = 0 ;i < n ; i++ ){
            int left = ( i > 0 ) ? (1LL*nums[i]*i - prefix): 0; 
            prefix += nums[i]; 
            int right = (i< n-1 ) ? ( (suffix - prefix) - 1LL*nums[i]*(n-1-i) ) : 0; 
            result[i] = left+right; 
        }
        return result;

    }
};