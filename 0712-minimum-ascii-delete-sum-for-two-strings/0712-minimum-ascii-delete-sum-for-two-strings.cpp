class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int>nums1 , nums2; int total =  0;
        for(auto&it: s1){
            nums1.push_back(it) ;
            total+=it;
        }
        for(auto& it : s2){
            nums2.push_back(it); 
            total+=it;
        }

        int n=  nums1.size() , m = nums2.size(); 
        vector<vector<int>>dp(n+1 , vector<int>(m+1  , 0 )); 

        for(int i  =1 ;i<=n ;i++ ){
            for(int j = 1 ; j<= m ;j++ ){
                dp[i][j] = ( s1[i-1] ==  s2[ j-1 ]) ? nums1[i-1]+dp[i-1][j-1] : max(dp[i-1][j] , dp[i][j-1]); 
            }
        }
        
        return total - 2*dp[n][m]; 
    }
};