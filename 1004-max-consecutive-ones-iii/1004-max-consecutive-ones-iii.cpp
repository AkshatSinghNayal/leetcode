#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int temp = k;
        int maxi = 0;

        while (right < n) {
            if (nums[right] == 0) {
                temp--;
            }

            // If temp becomes negative (i.e., we used too many flips), move the left pointer
            while (temp < 0) {
                if (nums[left] == 0) {
                    temp++;
                }
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }

        return maxi;
    }
};

