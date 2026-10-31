class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, vector<int>> mp;
        int maxi = -1;
        vector<pair<int,int>> temp;

        for (auto& it : logs) {
            temp.push_back({it[0], it[1]});
        }

        for (auto& it : logs) {
            int birth = it[0];
            int count = 0;

            for (auto& [b, d] : temp) {
                if (b <= birth && birth < d)
                    count++;
            }

            mp[count].push_back(birth);
            maxi = max(count, maxi);
        }

        sort(mp[maxi].begin(), mp[maxi].end());

        return mp[maxi][0];
    }
};