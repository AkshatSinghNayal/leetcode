class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); 
        int count = 0; 
        int m = strs[0].size(); 
        vector<bool> sorted(n - 1, false);  // CHANGE 1: Track ordered pairs
        
        for(int i = 0; i < m; i++) {
            bool fine = true;  // CHANGE 2: Move inside loop
            
            for(int j = 1; j < n; j++) {
                // CHANGE 3: Only check if not already sorted
                if(!sorted[j-1] && strs[j][i] < strs[j-1][i]) { 
                    count++; 
                    fine = false; 
                    break; 
                }
            }
            
            // CHANGE 4: If column is kept, update sorted pairs
            if(fine) {
                for(int j = 1; j < n; j++) {
                    if(strs[j][i] > strs[j-1][i]) {
                        sorted[j-1] = true;
                    }
                }
            }
            
            // CHANGE 5: Check if all pairs are sorted
            bool allSorted = true;
            for(int j = 0; j < n - 1; j++) {
                if(!sorted[j]) {
                    allSorted = false;
                    break;
                }
            }
            if(allSorted) break;
        }
        return count; 
    }
};