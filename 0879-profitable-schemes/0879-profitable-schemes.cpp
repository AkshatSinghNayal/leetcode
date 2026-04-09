class Solution {
public:
    const int MOD = 1e9+7;

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<int>>prev(n+1, vector<int>(minProfit+1, 0));

        // base case: no crimes, profit 0
        for(int j = 0; j <= n; j++)
            prev[j][0] = 1;

        for(int i = 1; i <= m; i++){
            vector<vector<int>>curr(n+1, vector<int>(minProfit+1, 0));
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= minProfit; k++){
                    // not take crime i-1
                    curr[j][k] = prev[j][k];

                    // take crime i-1 if enough members
                    if(j >= group[i-1]){
                        int prevProfit = max(0, k - profit[i-1]);
                        curr[j][k] = (curr[j][k] + prev[j - group[i-1]][prevProfit]) % MOD;
                    }
                }
            }
            prev = curr;
        }

        return prev[n][minProfit];
    }
};