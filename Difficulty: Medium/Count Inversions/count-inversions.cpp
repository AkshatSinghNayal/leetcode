class Solution {
public:
    long long inversionCount(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Coordinate compression
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        
        auto getIndex = [&](int x) {
            return (int)(lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1);
        };
        
        // Step 2: Fenwick Tree
        vector<int> BIT(n+2, 0);
        auto update = [&](int idx) {
            for (; idx<=n; idx += idx&-idx) BIT[idx]++;
        };
        auto query = [&](int idx) {
            long long sum=0;
            for (; idx>0; idx-=idx&-idx) sum += BIT[idx];
            return sum;
        };
        
        // Step 3: Traverse from right to left
        long long inv_count = 0;
        for (int i=n-1; i>=0; i--) {
            int idx = getIndex(arr[i]);
            inv_count += query(idx-1); // numbers smaller than arr[i]
            update(idx);
        }
        return inv_count;
    }
};
