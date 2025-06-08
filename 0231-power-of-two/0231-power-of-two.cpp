class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if n is positive and satisfies the condition for power of two
        if (n > 0 && (n & (n - 1)) == 0) {
            return true;
        }
        return false;
    }
};