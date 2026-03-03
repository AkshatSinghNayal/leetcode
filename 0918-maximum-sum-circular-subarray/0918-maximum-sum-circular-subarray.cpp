class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];
        
        for (int num : nums) {
            totalSum += num;
            
            // Kadane for max subarray
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            
            // Kadane for min subarray
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }
        
        // If all elements are negative
        if (maxSum < 0)
            return maxSum;
        
        return max(maxSum, totalSum - minSum);
    }
};