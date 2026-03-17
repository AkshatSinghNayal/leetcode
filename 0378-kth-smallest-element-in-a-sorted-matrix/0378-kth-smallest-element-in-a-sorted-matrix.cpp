class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n  = matrix[0].size() ;
        for(auto& it : matrix){
            for(int i  = 0 ; i<n ; i++ ){
                pq.push(it[i]);
            }
        }

       int i = 1 ;
        while(!pq.empty()){
            auto ele= pq.top();
            // cout << ele << " " ;
            pq.pop();

            if( i == k) return ele ;

            i++;

        }

        return -1 ;
    }
};