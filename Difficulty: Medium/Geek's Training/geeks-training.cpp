class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0)); 
        
        // Initializing dp for day 0
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]); 
        dp[0][2] = max(arr[0][1], arr[0][0]); 
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); 
        
        if (n == 1) return dp[0][3]; 
        
        // DP for subsequent days
        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0; 
                // Update dp[day][last] by considering the previous day's tasks
                for (int task = 0; task < 3; task++) {
                    if (task != last) {  // Ensure we don't repeat the same task
                        dp[day][last] = max(dp[day][last], dp[day - 1][task] + arr[day][task]);
                    }
                }
            }
        }
        
        return dp[n - 1][3]; 
    }
};
