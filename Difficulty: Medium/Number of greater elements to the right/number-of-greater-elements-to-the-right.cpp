class Solution {
public:
    vector<int> count_NGE(vector<int>& arr, vector<int>& indices) {
        int n = arr.size();
        vector<int> nextGreaterCount(n, 0);

        // Brute force counting (correct way)
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) cnt++;
            }
            nextGreaterCount[i] = cnt;
        }

        // Answer for queries
        vector<int> ans;
        for (int idx : indices) {
            ans.push_back(nextGreaterCount[idx]);
        }
        return ans;
    }
};
