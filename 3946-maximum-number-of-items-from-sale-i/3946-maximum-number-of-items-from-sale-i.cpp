class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int bud) {
        int n = items.size();

        vector<int> bonus(n , 0);

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;

       vector<int>prev(bud + 1 , 0);

        for(int i = 1 ; i <= n ; i++){
       vector<int>curr(bud + 1 , 0);

        int price = items[i-1][1];

    for(int budget = 0 ; budget <= bud ; budget++){

        int take = ( budget >= price ) ? prev[budget-price] + 1 + bonus[i-1] : 0 ;
        int notTake = prev[budget] ;

        curr[budget] = max( take , notTake ) ;
    }

    for(int budget = price ; budget <= bud ; budget++)
        curr[budget] = max( curr[budget] , curr[budget-price] + 1 ) ;

        prev= curr ; 
}

        return prev[bud];
    }
};