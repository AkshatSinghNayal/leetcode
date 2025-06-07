class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> setBits(n+1);
        setBits[0] = 0;

        for(int i=1; i<=n; i++){
            // if i is even, the LSB is 0, then right shifting by 1 won't lose any 1s
            // if i is odd, the LSB is 1, then right shifting by 1 would lose a 1
            // (right shifting by 1 is like dividing by 2)
            // LSB - Least significant bit
            setBits[i] = setBits[i/2] + i%2;
        }

        return setBits;
    }
};