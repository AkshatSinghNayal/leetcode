class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return 0;
        
        int count = 0; 
        int i = 0;
        
        while(i < n - 1){
            count++; 
            int jump = nums[i];
            
            // If we can reach the end in this jump, we're done
            if(i + jump >= n - 1) break;
            
            int futureJump = 0; 
            int bestIndex = i;
            
            // Check all positions we can reach from current position
            for(int j = 1; j <= jump; j++){
                int index = i + j;
                if(index < n){
                    // Pick the index that can reach farthest
                    if(index + nums[index] > bestIndex + futureJump){
                        futureJump = nums[index]; 
                        bestIndex = index; 
                    }
                }
            }
            
            i = bestIndex;
        }
        return count; 
    }
};