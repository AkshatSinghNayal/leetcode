class Solution {
public:
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // 1. Store {digit sum, number}
        vector<pair<int, int>> ok;

        for (int x : nums) {
            ok.push_back({digitSum(x), x});
        }

        // 2. Sort by digit sum, then by number
        sort(ok.begin(), ok.end(),
             [](const auto& a, const auto& b) {
                 if (a.first != b.first)
                     return a.first < b.first;

                 return a.second < b.second;
             });

        // 3. Build target sorted array
        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[i] = ok[i].second;
        }

        // 4. Store current position of each number
        vector<int> cur = nums;
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[cur[i]] = i;
        }

        // 5. Greedily put each number in its correct position
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (cur[i] == target[i])
                continue;

            int j = pos[target[i]];

            swap(cur[i], cur[j]);

            pos[cur[i]] = i;
            pos[cur[j]] = j;

            swaps++;
        }

        return swaps;
    }
};