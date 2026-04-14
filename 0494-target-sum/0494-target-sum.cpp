class Solution {
public:

    int findTargetSumWays(vector<int>& arr, int diff) {
        int n  = arr.size(); 
        int sum = accumulate(arr.begin() , arr.end() , 0); 
        if ((sum - diff) < 0 || (sum - diff) % 2 != 0) return 0;
        int target = (sum-diff)/2;
        vector<int>prev(target+1 ,0); 
        
        prev[0] = 1; 


        for(int i = 1; i<= n ; i++ ){
        vector<int>curr(target+1 ,0); 

            for(int j= 0; j<= target ; j++ ){
                int take = 0; 
                if( j >= arr[i-1]){
                    take =prev[j-arr[i-1]];  
                }
                int notTake = prev[j]; 


                curr[j] = (take + notTake ); 
            }
            prev = curr; 
        }
        return prev[target]; 
    }
};