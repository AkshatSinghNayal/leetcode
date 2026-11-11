class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if( need1 == 0 and need2 == 0 ) return 0 ; 
        long long minCost = LLONG_MAX; 
        long long tryAll = (long long)need1*cost1+(long long)need2*cost2 ; 
        minCost = min(minCost,tryAll); 

        long long satisfyOneNeed = max(0 ,need2-need1); 
        long long cost_when_taken_need1 = (long long)need1*costBoth + satisfyOneNeed*cost2; 
        minCost =min(minCost ,cost_when_taken_need1 ); 

        long long satisfySecondNeed = max( 0 , need1 - need2 );
        long long cost_when_taken_need2 = (long long)need2*costBoth + satisfySecondNeed*cost1; 
        minCost = min(minCost , cost_when_taken_need2); 

        return minCost ; 
    }
};