class Solution {
public:

    // int solve( string s , int i , vector<int>& dp ){
    //     if( i == 0  and s[i] == '0') return 0; 
    //     if( i <= 0 ) return 1; 


    //     if(dp[i] != -1 ) return dp[i]; 

    //     int one = ( s[i] != '0' ) ? solve( s , i-1 , dp ) : 0 ;
    //     int two = 0; 
    //     int temp = 0 ; 
    //     if( i-1 >=0  ){
    //         temp = stoi( s.substr( i-1 , 2 )); 
    //         if(s[i-1] == '0') temp =0 ; 
    //     }
    //     if( temp>=1 and temp<=26 ){
    //        two = solve( s, i-2 , dp ); 
    //     }
        

    //     return dp[i] = one+two;
        
    // }

    int numDecodings(string s) {
        int n = s.size(); 
        vector<int>dp(n,0); 

        if( s[0] != '0' ) dp[0] =1; 

        for(int i  = 1 ;i< n ;i++ ){


            int one = ( s[i] != '0' ) ? dp[i-1] : 0 ;
            int two = 0; 
            int temp = 0 ; 


        if (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) {
            two = (i >= 2) ? dp[i-2] : 1;
        }
        

        dp[i] = one+two;
        
        }

        return dp[n-1] ; 
    }
};