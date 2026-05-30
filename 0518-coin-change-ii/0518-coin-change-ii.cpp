class Solution {
public:

    int change(int amt, vector<int>& coins) {
        int n  = coins.size(); 
        vector<int>prev(amt+1 , 0);
        prev[0] = 1; 
        for(int i = 1; i<= n ; i++ ){
            vector<int>curr(amt+1 , 0);

            for(int amount = 0 ; amount<= amt ; amount++ ){
                long long  take = ( amount>=coins[i-1] ) ? curr[amount-coins[i-1]] : 0 ; 
                long long notTake = prev[amount];
                curr[amount] = (take+notTake);
            }
            prev = curr ; 
        } 
        return prev[amt]; 
    }
};