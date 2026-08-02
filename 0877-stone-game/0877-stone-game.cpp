class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        int n  = nums.size() ; 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1 , vector<int>(2 , 0))); 
        double total = accumulate(nums.begin() , nums.end() , 0);  
       

        for(int index = n-1 ; index >=0 ; index-- ){
            for(int end = 1 ; end <=n  ; end++ ){
                if(   index > end )  continue;
                for(int player = 0 ; player<=1 ; player++ ){
                    int maxi = 0 ;

        if(player){
            int first = nums[index]+dp[index+1][end][1-player]; 
            int ending =  nums[end-1]+dp[index][end-1][1-player];

            maxi = max(first ,ending ); 
        }
        else{
            int first = dp[index+1][end][1-player]; 
            int ending = dp[index][end-1][1-player]; 

            maxi = min(first , ending); 
        }


                    dp[index][end][player] = maxi ; 
                }
            }
        }

        return dp[0][n][1]>=total/2.0 ? true : false; 
    }
};