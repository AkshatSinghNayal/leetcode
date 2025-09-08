class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;  // base cases
        int a = 1, b = 1;      // ways(0)=1, ways(1)=1
        for (int i = 2; i <= n; i++) {
            int c = a + b;     // current = sum of last two
            a = b;             // shift forward
            b = c;
        }
        return b;
    }
};
