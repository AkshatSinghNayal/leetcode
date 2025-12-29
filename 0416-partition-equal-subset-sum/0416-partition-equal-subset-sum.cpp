class Solution {
public:
    bool canPartition(vector<int>& arr) {
        long long sum = accumulate( arr.begin(),arr.end(),0);
        if( sum%2 != 0 ) return false; 
        long long total = sum/2 ;

         vector<bool>dp(total+1,false); 
        dp[0] =  true; 
        for(int i  = 0 ;i<arr.size() ; i++){
            for(int j = total ; j>=1 and j>= arr[i] ; j--){
                dp[j] = dp[j]||dp[ j - arr[i]] ; 
                if( dp[total]) return true; 
            }
        }
        return false;
    }
};