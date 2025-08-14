// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if (n <= 0) return false;
//         long long val = 1;
//         while (val < n) {
//             val *= 3;
//         }
//         return val == n;
//     }
// };
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
