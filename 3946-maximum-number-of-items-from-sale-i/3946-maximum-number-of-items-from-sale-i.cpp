class Solution {
public:

    int dp[1001][1501][2];  

    int solve(vector<vector<int>>& items , int budget , int i , bool bought , unordered_map<int,int>& mp , int n ){
        if(i>=n or budget == 0) return 0; 

        if(dp[i][budget][bought]!=-1) return dp[i][budget][bought]; 

        int take =0 ; 
        if( items[i][1] <= budget ){
            if(bought){
                take =1+mp[i]+solve(items, max(0 , budget-items[i][1]) , i , false , mp , n ); 
            }   
            else{
                take = 1+solve(items, max(0 , budget-items[i][1]) , i , false , mp , n );
            }
            take = max(take ,1+solve(items, max(0 , budget-items[i][1]) , i+1 , true , mp , n )); 

        }
        int notTake = solve(items,budget , i+1 , true , mp , n ); 


        return dp[i][budget][bought] = max(take , notTake ); 

    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<int,int>mp; 
        
        for(int i =0 ;i<n; i++ ){
            int ele = items[i][0];
            int count = 0; 
            for(int j = 0; j<n; j++ ){
                if(i==j) continue;
                if( items[j][0]%ele == 0 ) count++; 
            }
            mp[i] = count;
        }

        memset(dp,-1 , sizeof(dp)); 

        return solve(items , budget , 0 , true , mp , n); 
        
    }
};