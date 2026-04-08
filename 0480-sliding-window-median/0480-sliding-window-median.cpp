class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<pair<double,int>> leftSide;  // smaller half
        multiset<pair<double,int>, greater<pair<double,int>>> rightSide; // larger half
        vector<double> ans;
        int n = nums.size();
        int left = 0, right = 0;

        while(right < n) {
            double ele = (double)nums[right];
            pair<double,int> newPair = {ele, right};

            // insert into rightSide first
            rightSide.insert(newPair);

            // move smallest of rightSide to leftSide
            auto itRight = prev(rightSide.end()); // largest in rightSide (descending order)
            leftSide.insert(*itRight);
            rightSide.erase(itRight);

            // rebalance sizes
            if(leftSide.size() > rightSide.size() + 1) {
                auto itLeft = prev(leftSide.end());
                rightSide.insert(*itLeft);
                leftSide.erase(itLeft);
            }

            // remove outgoing element when window slides
            if(right - left + 1 > k) {
                pair<double,int> out = { (double)nums[left], left };
                if(leftSide.find(out) != leftSide.end()) {
                    leftSide.erase(leftSide.find(out));
                } else {
                    rightSide.erase(rightSide.find(out));
                }
                left++;

                // rebalance after removal
                if(leftSide.size() > rightSide.size() + 1) {
                    auto itLeft = prev(leftSide.end());
                    rightSide.insert(*itLeft);
                    leftSide.erase(itLeft);
                } else if(leftSide.size() < rightSide.size()) {
                    auto itRight2 = prev(rightSide.end());
                    leftSide.insert(*itRight2);
                    rightSide.erase(itRight2);
                }
            }

            // compute median if window has size k
            if(right - left + 1 == k) {
                double median;
                if(k % 2 != 0) {
                    median = prev(leftSide.end())->first; // max of leftSide
                } else {
                    double leftMax = prev(leftSide.end())->first;
                    double rightMin = prev(rightSide.end())->first;
                    median = (leftMax + rightMin) / 2.0;
                }
                ans.push_back(median);
            }

            right++;
        }

        return ans;
    }
};