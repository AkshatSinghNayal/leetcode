class Solution {
public:

    int solve( vector<vector<int>>&dp , string& s , string& p , int  i , int j ){
        //base
        if( i<0 and j<0 ) return 0;
        if( i <0 ){
            while(j>=0 and p[j] == '*') j--;
            if( j <0 ) return 0;
            else return INT_MIN;
        }
        if(j<0 or i<0) return INT_MIN;


        if( dp[i][j] != -1 ) return dp[i][j];

        // if( s[i] != p[j] and p[j]!='?' or p[j]!='*') return INT_MIN;

        int take = INT_MIN ;
        int take3 = INT_MIN ; 
        if(s[i] == p[j] or p[j] == '?') take = 1+solve(dp ,s,p,i-1,j-1);
        if(p[j] == '*'){
            int case1 = 1+solve(dp,s,p,i-1,j-1);
            int case2 = solve(dp,s,p,i,j-1);
            int case3 = 1+solve(dp,s,p,i-1,j);
            take3 = max({ case1 , case2 , case3 }); 
        }
        return dp[i][j] = max({take , take3}); 

    }

    bool isMatch(string s, string p) {
        int n = s.size() , m = p.size();
        vector<vector<int>>dp(n,vector<int>(m , -1 )); 
        int ans = solve( dp, s, p, n-1 , m-1 ); 

        // cout<<"length->"<<s.size() << endl;

        // for(auto& it : dp ){
        //     for(auto& temp : it ){
        //         cout<<temp<< " ";
        //     }
        //     cout<<endl;
        // }

        // cout<<ans<< " ";
        return ans == n;
    }
};