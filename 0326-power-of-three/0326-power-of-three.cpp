class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        long long val = 1;
        while (val < n) {
            val *= 3;
        }
        return val == n;
    }
};
