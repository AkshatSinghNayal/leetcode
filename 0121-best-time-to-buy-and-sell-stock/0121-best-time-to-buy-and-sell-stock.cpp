class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long profit = 0 , mini= prices[0]; 
        int n =  prices.size(); 

        for(int i = 0;  i< n ; i++ ){
            profit= ( prices[i]-mini > profit ) ? prices[i]-mini : profit ; 
            mini = ( mini > prices[i]) ? prices[i] : mini; 
        }
        return (int)profit ; 
    }
};