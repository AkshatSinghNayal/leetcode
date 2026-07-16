class Solution {
public:
    int dp[601][101][101]; 

    // int solve( vector<pair<int,int>>&data , int one , int zero , int i ){
    //     //base
    //     if( i< 0 ) return 0;

    //     if(dp[i][one][zero] != -1  ) return dp[i][one][zero]; 
    //     auto [ t_one , t_zero ] = data[i]; 
    //     int take = ( t_one <= one and t_zero <= zero ) ? 1 + solve(data , one-t_one , zero-t_zero , i-1 ) : 0;
    //     int notTake = solve(data , one , zero , i-1 );

    //     return dp[i][one][zero] = max(take , notTake);

    // }

    int findMaxForm(vector<string>& strs, int m, int n1) {
        int n  = strs.size(); 
        vector<pair<int,int>>data;
        for(auto& it : strs ){      
        int one = 0 ,zero = 0;   
            for(int i  = 0;i<it.size(); i++ ){
                char ch = it[i]; 
                if(ch == '0') zero++;
                else one++;
            }
            data.push_back({one , zero}); 
        }
        memset(dp,0,sizeof(dp));


        for(int i =1 ; i<=n ; i++ ){
            auto [ t_one , t_zero ] = data[i-1]; 
            for(int one =n1 ; one>=0; one-- ){
                for(int zero = m; zero>=0; zero-- ){

                    int take = ( t_one <= one and t_zero <= zero ) ? 1 + dp[i-1][one-t_one][zero-t_zero] : 0;
                    int notTake = dp[i-1][one][zero];
                    dp[i][one][zero] = max(take , notTake);
                }
            }
        }

        return dp[n][n1][m]; 


    }
};