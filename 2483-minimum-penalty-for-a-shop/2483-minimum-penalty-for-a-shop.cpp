class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        // penalty[i] = penalty if we close at hour i
        // Before i: count 'N' (shop open, no customers)
        // From i onwards: count 'Y' (shop closed, customers come)
        
        int countN = 0; // 'N's before current position
        int countY = 0; // total 'Y's in string
        
        // Count total Y's
        for (char c : customers) {
            if (c == 'Y') countY++;
        }
        
        int minPenalty = countY; // closing at hour 0
        int bestHour = 0;
        
        for (int i = 0; i < n; i++) {
            // Update counts as we move the closing time
            if (customers[i] == 'N') {
                countN++;
            } else {
                countY--;
            }
            
            int penalty = countN + countY;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }
        
        return bestHour;
    }
};