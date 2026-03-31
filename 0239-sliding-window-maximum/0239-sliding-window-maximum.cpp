class Solution {
public:

    class comp {
    public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) {
                return a.second > b.second; 
            }
            return a.first < b.first;
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, right = 0, n = nums.size(); 
        vector<int> ans; 
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;

        while (right < n) {
            pq.push({nums[right], right});

            if (right - left + 1 == k) {

                // Remove elements out of window
                while (!pq.empty() && pq.top().second < left) {
                    pq.pop();
                }

                ans.push_back(pq.top().first);
                left++;
            }
            right++;
        }
        return ans; 
    }
};