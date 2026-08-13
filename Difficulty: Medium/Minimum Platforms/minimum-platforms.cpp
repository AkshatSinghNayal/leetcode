class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int platforms = 0;
        int ans = 0;

        while (i < arr.size() && j < dep.size()) {
            if (arr[i] <= dep[j]) {
                platforms++;
                ans = max(ans, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }

        return ans;
    }
};