#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    int findMaxForm(vector<string>& strs, int zero, int one) {
        int n  = strs.size(); 
        vector<pair<int,int>>nums(n); 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(one+1,vector<int>(zero+1,0))); 

        for(int i = 0 ;i<n ;i++ ){
            int one1 = 0, zero1 = 0 , size = strs[i].size() ; 
            for(int j  = 0; j<size ; j++ ){
                char ch = strs[i][j];
                if(ch =='1') one1++; 
                else zero1++; 
            }
            nums[i] = { one1 , zero1}; 
        }

        

        for(int i  =1; i<= n; i++ ){
            for(int j =0 ; j<= one ;j++ ){
                for(int k = 0; k<= zero ;k++ ){
                    int take = ( nums[i-1].first <=j and nums[i-1].second<=k ) ? 1+dp[i-1][j-nums[i-1].first][k-nums[i-1].second] : 0 ;
                    int notTake = dp[i-1][j][k]; 
                    dp[i][j][k] = max(take,notTake); 
                }
            }
        }


        return dp[n][one][zero]; 
    
    }
};


