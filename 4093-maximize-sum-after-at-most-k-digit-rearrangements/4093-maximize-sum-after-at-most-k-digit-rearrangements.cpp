
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> gain;

        for (int x : nums) {
            string s = to_string(x);
            sort(s.rbegin(), s.rend());

            int after = stoi(s);
            gain.push_back({after - x, x});
        }

        sort(gain.rbegin(), gain.rend());

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (k > 0 && gain[i].first > 0) {
                sum += gain[i].second + gain[i].first;
                k--;
            } else {
                sum += gain[i].second;
            }
        }

        return sum;
    }
};
