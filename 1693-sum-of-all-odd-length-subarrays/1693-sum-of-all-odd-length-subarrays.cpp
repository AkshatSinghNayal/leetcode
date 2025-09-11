#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            // Total subarrays containing arr[i]
            int totalSubarrays = (i + 1) * (n - i);

            // Number of odd-length subarrays
            int oddCount = (totalSubarrays + 1) / 2;

            // Contribution of arr[i]
            totalSum += arr[i] * oddCount;
        }

        return totalSum;
    }
};
