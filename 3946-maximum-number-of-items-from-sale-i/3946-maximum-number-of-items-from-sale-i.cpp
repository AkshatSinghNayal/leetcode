class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int bud) {
        int n = items.size();

        vector<int> bonus(n , 0);

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;

        vector<vector<int>> dp(n + 1 , vector<int>(bud + 1 , 0));

        for(int i = 1 ; i <= n ; i++){

            int price = items[i - 1][1];

            for(int budget = 0 ; budget <= bud ; budget++){

                int notTake = dp[i - 1][budget];

                int take = (budget >= price)
                    ? dp[i - 1][budget - price] + 1 + bonus[i - 1]
                    : 0;

                dp[i][budget] = max(take , notTake);
            }

            for(int budget = price ; budget <= bud ; budget++)
                dp[i][budget] = max(dp[i][budget] ,
                                    dp[i][budget - price] + 1);
        }

        return dp[n][bud];
    }
};