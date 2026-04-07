#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // multiset to maintain sorted order of the window
        multiset<int> window(nums.begin(), nums.begin() + k);
        
        // iterator pointing to the "middle" element (median)
        auto mid = next(window.begin(), k / 2);
        
        vector<double> medians;

        for (int i = k; ; i++) {
            // Compute median:
            // - For odd k, *mid is the median
            // - For even k, average *mid and previous element
            medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);

            // If we reached the end of the array, return the result
            if (i == nums.size()) return medians;

            // Insert the new element from the right of the window
            window.insert(nums[i]);
            if (nums[i] < *mid) mid--; // median shifts left if new element is smaller

            // Remove the element leaving the window (from the left)
            if (nums[i - k] <= *mid) mid++; // median shifts right if removed element <= median
            window.erase(window.lower_bound(nums[i - k]));
        }
    }
};