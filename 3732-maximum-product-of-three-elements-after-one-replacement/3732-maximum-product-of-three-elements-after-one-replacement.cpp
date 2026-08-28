class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long largest = LLONG_MIN, secondLargest = LLONG_MIN;
        long long smallest = LLONG_MAX, secondSmallest = LLONG_MAX;

        for (long long x : nums) {
            if (x >= largest) {
                secondLargest = largest;
                largest = x;
            } else if (x > secondLargest) {
                secondLargest = x;
            }

            if (x <= smallest) {
                secondSmallest = smallest;
                smallest = x;
            } else if (x < secondSmallest) {
                secondSmallest = x;
            }
        }

        long long M = 100000LL;

        long long ans = LLONG_MIN;

        // Replace one element with +100000
        ans = max(ans, M * largest * secondLargest);
        ans = max(ans, M * smallest * secondSmallest);

        // Replace one element with -100000
        ans = max(ans, -M * largest * secondLargest);
        ans = max(ans, -M * smallest * secondSmallest);

         ans = max(ans, -M * largest * smallest);
        ans = max(ans, M * smallest * largest);


        return ans;
    }
};
