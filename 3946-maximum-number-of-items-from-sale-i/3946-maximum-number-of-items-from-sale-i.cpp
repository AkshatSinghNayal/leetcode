class Solution {
public:

    int dp[1001][1501][2]; 

    int solve(int idx ,vector<vector<int>>& items,unordered_map<int,int>&mp, int amount , int yes){
        //base
        if(idx < 0 ) return 0;

        if(dp[idx][amount][yes] != -1 ) return dp[idx][amount][yes]; 

        int take = 0;

        if (yes) {
            take = (amount >= items[idx][1]) ? mp[idx] + 1 + solve(idx, items, mp, amount - items[idx][1], 1 - yes) : 0;
        }
        else {
            take = (amount >= items[idx][1]) ? 1 + solve(idx, items, mp, amount - items[idx][1], yes) : 0;
            // int another = (amount >= items[idx][1]) ? 1 + solve(idx-1, items, mp, amount - items[idx][1], 1-yes) : 0;
            // take = max(take, another);
        }

        int notTake = max(solve( idx-1 , items , mp , amount, yes),solve(idx-1,items,mp,amount,1-yes));

        return dp[idx][amount][yes] = max(take,notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        unordered_map<int,int>mp;
        int n = items.size();
        

        for(int i = 0;i<n; i++ ){
            int ele = items[i][0]; 
            for(int j =0;j<n; j++ ){
                if(i==j) continue;
                mp[i]+= ( items[j][0] % ele == 0 ) ? 1 : 0; 
            }
        }

        // for(auto& it : items){
        //     cout<< it[0] << "->" << it[1] <<endl;
        // }

        memset(dp,-1,sizeof(dp)); 

        // for(auto&[ele , count] : mp ){
        //     cout<< ele <<"->" << count << endl;
        // }

        return solve(n-1,items,mp,budget,1);


        return  0; 
    }
};