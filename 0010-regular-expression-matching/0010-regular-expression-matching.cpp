class Solution {
public:

    int solve( vector<vector<int>>&dp , string& s , string& p , int  i , int j ){
        //base
        if( i<0 and j<0 ) return 0;
        if( i <0 ){
            while(j>=0 and p[j] == '*'){
                j-=2;
            }
            if( j <0 ) return 0;
            else return INT_MIN;
        }
        if(j<0 or i<0) return INT_MIN;
        
       
        if( dp[i][j] != -1 ) return dp[i][j];

        int take = INT_MIN; 
        int take1 = INT_MIN; 
        if(s[i] == p[j] or p[j] == '.') take = 1+solve(dp,s,p,i-1,j-1); 
        
        if(p[j] == '*'){
            int case1 = INT_MIN, case2 = INT_MIN , case3 = INT_MIN; 
            
                char ch = p[j-1]; 
                if( ch == s[i]){
                    case1 = max(1+solve(dp,s,p,i-1,j-2),1+solve(dp,s,p,i-1,j)); 
                }
                case2=  solve(dp,s,p,i,j-2);
                if(ch=='.'){
                    case3 = max(1+solve(dp,s,p,i-1,j-2),1+solve(dp,s,p,i-1,j)); 
                }
                
                take1 = max({case1,case2,case3}); 
            
        }


        
       return dp[i][j] = max({take,take1}); 

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