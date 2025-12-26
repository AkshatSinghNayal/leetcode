class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(); 
        
        // Key fix: arrays should be size n+1 for closing times 0 to n
        vector<int> prefix(n+1, 0), suffix(n+1, 0); 
        
        // suffix[i] = count of 'N' from 0 to i-1 (penalty when open)
        for(int i = 1; i <= n; i++) {
            suffix[i] = suffix[i-1] + (customers[i-1] == 'N' ? 1 : 0);
        }
        
        // prefix[i] = count of 'Y' from i to n-1 (penalty when closed)
        for(int i = n-1; i >= 0; i--) {
            prefix[i] = prefix[i+1] + (customers[i] == 'Y' ? 1 : 0);
        }
        
        int minPenalty = INT_MAX;
        int bestHour = 0;
        
        // Check all closing times from 0 to n
        for(int j = 0; j <= n; j++) {
            int penalty = suffix[j] + prefix[j];
            if(penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j;
            }
        }
        
        return bestHour;
    }
};