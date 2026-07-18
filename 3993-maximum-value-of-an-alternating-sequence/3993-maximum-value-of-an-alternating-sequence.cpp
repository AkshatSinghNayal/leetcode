class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long operations = n - 1;
        
        if (operations == 0) return s;

        // Total UP steps we can take
        long long up_steps = (operations + 1) / 2;
        
        // Count only the down-steps that happen BEFORE our highest peak
        long long down_steps = operations-up_steps;
        if (operations % 2 == 0) {
            down_steps = (operations / 2) - 1; 
        }

        long long one = 1LL * s + (up_steps * m) - down_steps;

        return one;
    }
};