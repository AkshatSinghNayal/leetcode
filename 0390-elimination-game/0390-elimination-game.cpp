class Solution {
public:
    int lastRemaining(int n) {
        long long head = 1, step = 1, remaining = n;
        bool left = true;

        while (remaining > 1) {
            if (left || (remaining % 2 == 1)) {
                head += step;
            }
            step *= 2;
            remaining /= 2;
            left = !left;
        }

        return (int)head;
    }
};
