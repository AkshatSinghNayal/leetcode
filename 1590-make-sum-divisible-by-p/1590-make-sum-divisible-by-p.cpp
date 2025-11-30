class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        // Step 1: Calculate the total sum of the array modulo p
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum = (totalSum + nums[i]) % p;
        }
        
        // If totalSum % p == 0, the entire array is already divisible by p
        if (totalSum % p == 0) return 0;
        
        // Step 2: Initialize the prefix sum, the map, and the answer
        unordered_map<int, int> prefixMap;
        int prefixSum = 0;
        prefixMap[0] = -1; // To handle cases where the subarray starts from index 0
        int ans = n; // Start with the maximum possible answer
        
        // Step 3: Iterate over the array
        for (int i = 0; i < n; i++) {
            // Step 4: Update the current prefix sum
            prefixSum = (prefixSum + nums[i]) % p;
            
            // Step 5: Calculate the difference required to match the target sum
            int target = (prefixSum - totalSum + p) % p;
            
            // Step 6: If we find the required prefix sum in the map, update the answer
            if (prefixMap.find(target) != prefixMap.end()) {
                ans = min(ans, i - prefixMap[target]);
            }
            
            // Step 7: Store the current prefix sum in the map
            prefixMap[prefixSum] = i;
        }
        
        // Step 8: If no valid subarray found, return -1
        return ans == n ? -1 : ans;
    }
};
