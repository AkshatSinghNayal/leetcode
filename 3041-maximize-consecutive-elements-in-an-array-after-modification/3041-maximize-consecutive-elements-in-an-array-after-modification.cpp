
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int, int> mp, dp;

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

        int maxi = 0;

        for (auto& x : nums) {
            mp[x]++;
        }

        for (auto& [ele, it] : mp) {
            pq.push({ele, it});
        }

        while (!pq.empty()) {
            auto [ele, temp] = pq.top(); pq.pop();

            for (int i = 0; i < min(temp, 2); i++) {
                dp[ele + 1] = max(dp[ele + 1], dp[ele] + 1);
                dp[ele] = max(dp[ele], dp[ele - 1] + 1);

                maxi = max({maxi, dp[ele], dp[ele + 1]});
            }
        }

        return maxi;
    }
};
