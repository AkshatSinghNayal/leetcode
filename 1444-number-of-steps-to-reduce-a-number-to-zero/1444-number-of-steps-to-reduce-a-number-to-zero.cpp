class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;

        int steps = 0;
        while (num > 0) {
            // if the number is odd, subtract 1 (last bit = 1)
            // if even, just shift right
            steps += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        // subtract 1 because the last subtraction happens when num becomes 0
        return steps - 1;
    }
};
