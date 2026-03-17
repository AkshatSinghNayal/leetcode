class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        // Step 1: push first element of each row
        for(int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        // Step 2: process k elements
        while(k--) {
            auto [val, r, c] = pq.top();
            pq.pop();

            // If next element exists in same row, push it
            if(c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }

            if(k == 0) return val;
        }

        return -1;
    }
};