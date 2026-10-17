class DSU {
public:
    vector<int> parent, sz;
    int components;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        components--;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<long long, int>> ok;

        // 1. Calculate digit sums
        for (auto& it : nums) {
            int temp = it;
            long long sum = 0;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            ok.push_back({sum, it});
        }

        // 2. Sort by digit sum, then by number
        sort(ok.begin(), ok.end(),
             [](const auto& a, const auto& b) {
                 if (a.first == b.first)
                     return a.second < b.second;

                 return a.first < b.first;
             });

        int n = nums.size();

        // 3. Store each number's target index
        unordered_map<int, int> targetPos;

        for (int i = 0; i < n; i++) {
            targetPos[ok[i].second] = i;
        }

        // 4. Connect current index to target index
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            dsu.unite(i, targetPos[nums[i]]);
        }

        // 5. Minimum swaps
        return n - dsu.components;
    }
};