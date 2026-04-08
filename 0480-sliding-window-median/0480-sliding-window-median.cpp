#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // max heap (left side) stores smaller half
        multiset<pair<int,int>> leftSide;
        // min heap (right side) stores larger half
        multiset<pair<int,int>, greater<pair<int,int>>> rightSide;

        vector<double> ans;
        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            pair<int,int> newPair = {nums[i], i};

            // insert into rightSide first
            rightSide.insert(newPair);

            // balance: move smallest of rightSide to leftSide
            auto rightMin = prev(rightSide.end()); // largest in rightSide due to greater
            leftSide.insert(*rightMin);
            rightSide.erase(rightMin);

            // rebalance sizes
            if(leftSide.size() > rightSide.size() + 1) {
                auto leftMax = prev(leftSide.end());
                rightSide.insert(*leftMax);
                leftSide.erase(leftMax);
            }

            // remove the element going out of window
            if(i >= k) {
                pair<int,int> out = {nums[i - k], i - k};
                if(leftSide.find(out) != leftSide.end()) {
                    leftSide.erase(leftSide.find(out));
                } else {
                    rightSide.erase(rightSide.find(out));
                }

                // rebalance again after removal
                if(leftSide.size() > rightSide.size() + 1) {
                    auto leftMax = prev(leftSide.end());
                    rightSide.insert(*leftMax);
                    leftSide.erase(leftMax);
                } else if(leftSide.size() < rightSide.size()) {
                    auto rightMin2 = prev(rightSide.end());
                    leftSide.insert(*rightMin2);
                    rightSide.erase(rightMin2);
                }
            }

            // calculate median
            if(i >= k - 1) {
                double median;
                if(k % 2 != 0) { // odd
                    median = (double)prev(leftSide.end())->first;
                } else { // even
                    double leftMaxVal = (double)prev(leftSide.end())->first;
                    double rightMinVal = (double)prev(rightSide.end())->first; // largest in rightSide
                    median = (leftMaxVal + rightMinVal) / 2.0;
                }
                ans.push_back(median);
            }
        }

        return ans;
    }
};