class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;  // No jumps needed if the array size is 1 or less
        
        int left = 0, right = 0, far = 0, jump = 0;
        
        while (right < nums.size() ) {  // We don't need to jump if we're already at the last element
            far = 0;  // Reset far for each jump range
            
            // Explore all positions within the current jump's range
            for (int i = left; i <= right; i++) {
                far = max(far, i + nums[i]);  // Calculate the farthest we can reach from i
            }
            
            // After exploring, we've used one jump
            jump++;
            
            // Update left to be the end of the current jump range, and right to the farthest we can go
            left = right + 1;
            right = far;
            
            // If we can reach the end, break early
            if (right >= nums.size() - 1) break;
        }
        
        return jump;
    }
};
