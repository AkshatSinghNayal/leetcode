class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate( nums.begin(),nums.end(),0);
        if( sum%2 != 0 ) return false; 
        long long target = sum/2; 

        int n = nums.size();
        
        // Create the dp table: n rows (items), sum+1 columns (target sum)
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        
        // Initialize the first column (target sum 0 is always achievable)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;  // Sum 0 is always achievable (take no elements)
        }
        
        // Initialize the first row (consider only nums[0])
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int tar = 1; tar <= target; tar++) {
                bool notTake = dp[i-1][tar];  // Do not include nums[i]
                bool take = false;
                
                if (nums[i] <= tar) {
                    take = dp[i-1][tar - nums[i]];  // Include nums[i]
                }

                dp[i][tar] = take || notTake; 
                if( dp[i][target] == true ) return true;  // Take or not take the element
            }
        }

        // The last cell of the dp table contains the answer
        return false ; 
    }
};