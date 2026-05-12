class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size(); 
        if( amount == 0 ) return 0; 
        vector<int>prev(amount+1,INT_MAX-1);
        prev[0] =0;
        for(int i = 1 ; i<= n; i++ ){
        vector<int>curr(amount+1,INT_MAX-1);

            for(int j = 0 ; j<=amount ; j++ ){
                int take = ( coins[i-1] <= j ) ? 1+curr[j-coins[i-1]]: INT_MAX-1; 
                int notTake = prev[j];

                curr[j] = min(take,notTake);
            }
                prev=curr;
        }

        return prev[amount] == INT_MAX-1 ? -1 : prev[amount];
    }
};