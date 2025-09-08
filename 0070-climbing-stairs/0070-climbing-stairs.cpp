class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2.0;
        double psi = (1 - sqrt5) / 2.0;
        double fib = (pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5;
        return (int)round(fib);
    }
};
