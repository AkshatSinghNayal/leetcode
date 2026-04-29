class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        for (auto& row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }

        int base = arr[0];
        for (int val : arr) {
            if ((val - base) % x != 0) return -1;
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];

        int operations = 0;
        for (int val : arr) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};