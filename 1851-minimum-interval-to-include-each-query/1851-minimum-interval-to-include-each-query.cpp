class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& nums, vector<int>& queries) {
        int n = nums.size();

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        // {length, end}

        vector<int> ans(queries.size(), -1);

        int i = 0;

        for(auto& [query, index] : q) {

            // add intervals whose start <= query
            while(i < n && nums[i][0] <= query) {
                int start = nums[i][0];
                int end = nums[i][1];

                pq.push({end - start + 1, end});
                i++;
            }

            // remove intervals that cannot contain query
            while(!pq.empty() && pq.top().second < query) {
                pq.pop();
            }

            if(!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};