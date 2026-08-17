class Solution {
public:

    

    bool check(vector<string>& words ,  int prev , int idx ){
        int i = 0 , j = 0 , count = 0 ; 
        if(words[prev].size() != words[idx].size() -1) return false;

        while( count <=1 and j < words[idx].size() and i < words[prev].size() ){
            if( words[prev][i] == words[idx][j] ){
                i++; j++; 
            }
            else{
                count++; 
                j++; 
            }
        }
        return ( i == words[prev].size() ) ? true : false;
    }

    // int solve(vector<string>& words , int i , int prev , int n ){
    //     //base
    //     if( i >= n ) return 0; 

    //     if(dp[i][prev+1] != -1 ) return dp[i][prev+1];

    //     int take = ( prev == -1 or check(words , prev , i) ) ? 1+solve(words, i+1 , i , n ) : 0 ;
    //     int notTake = solve( words , i+1 , prev , n ); 


    //     return dp[i][prev+1] = max( take , notTake ); 
    // }

    int longestStrChain(vector<string>& words) {
        sort( words.begin() , words.end() ,[&]( auto a , auto b ){
            return a.size() < b.size() ; 
        } ); 
        int n = words.size(); 
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0)); 

        for(int i =  n-1 ;i>=0 ;i-- ){
            for( int prev = n-1 ; prev>=-1 ; prev-- ){
                int take = ( prev == -1 or check(words , prev , i) ) ? 1+dp[i+1][i+1]: 0 ;
                int notTake = dp[i+1][prev+1]; 
                
                dp[i][prev+1] = max( take , notTake ); 

            }
        }
        return dp[0][0]; 
    }
};