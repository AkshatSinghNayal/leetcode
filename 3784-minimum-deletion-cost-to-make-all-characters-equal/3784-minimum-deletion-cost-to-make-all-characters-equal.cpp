class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char, long long> mp;
        long long total = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] += cost[i];
            total += cost[i];
        }

        long long maxi = 0;
        for (auto &it : mp) {
            maxi = max(maxi, it.second);
        }

        return total - maxi;
    }
};
