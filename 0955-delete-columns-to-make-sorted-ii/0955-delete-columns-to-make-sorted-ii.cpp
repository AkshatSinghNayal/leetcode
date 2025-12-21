class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); 
        int count = 0; 
        int m = strs[0].size(); 
        vector<bool> sorted(n - 1, false);  // FIX 1: n-1 instead of n
        
        for(int col = 0; col < m; col++) {
            bool deleted = false;
            
            for(int row = 0; row < n-1; row++) { 
                if(!sorted[row] && strs[row][col] > strs[row+1][col]){
                    count++;
                    deleted = true; 
                    break; 
                }
            }
            if(deleted){
                continue; 
            }
            for(int i = 0; i < n - 1; i++){  // FIX 2: n-1 instead of n
                 sorted[i] = sorted[i] | (strs[i][col] < strs[i+1][col]);  
            }
        }
        return count; 
    }
};
