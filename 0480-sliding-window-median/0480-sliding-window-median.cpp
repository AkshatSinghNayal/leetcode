class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<pair<long,int>> lo; // lower half — max at end
        multiset<pair<long,int>> hi; // upper half — min at begin
        vector<double> ans;
        int n = nums.size(), left = 0;

        for(int right = 0; right < n; right++){
            pair<long,int> newPair = {nums[right], right};

            // Step 1: always insert into hi first
            hi.insert(newPair);

            // Step 2: size balance — lo should always be >= hi
            if(lo.size() < hi.size()){
                auto it = hi.begin(); // min of hi
                lo.insert(*it);
                hi.erase(it);
            }

            // Step 3: ordering cross check — lo's max should be <= hi's min
            if(!lo.empty() && !hi.empty() &&
               prev(lo.end())->first > hi.begin()->first){
                auto loMax = prev(lo.end());
                auto hiMin = hi.begin();
                lo.insert(*hiMin);
                hi.insert(*loMax);
                lo.erase(loMax);
                hi.erase(hiMin);
            }

            // Remove element going out of window
            if(right - left + 1 > k){
                pair<long,int> toRemove = {nums[left], left};
                if(lo.find(toRemove) != lo.end()) lo.erase(toRemove);
                else hi.erase(toRemove);

                // Rebalance after removal
                if(lo.size() < hi.size()){
                    auto it = hi.begin();
                    lo.insert(*it);
                    hi.erase(it);
                }
                else if(lo.size() > hi.size() + 1){
                    auto it = prev(lo.end());
                    hi.insert(*it);
                    lo.erase(it);
                }
                left++;
            }

            // Compute median when window is full
            if(right - left + 1 == k){
                double median;
                if(k % 2 != 0)
                    median = prev(lo.end())->first;
                else
                    median = (prev(lo.end())->first + hi.begin()->first) / 2.0;
                ans.push_back(median);
            }
        }
        return ans;
    }
};