class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = heights.size();
        
        for (int i = 1; i < n; i++) {
            int difference = heights[i-1] - heights[i]; 
            if( difference <0 ){
                pq.push(-difference); 
            }
            if( pq.size() > ladders ){
                bricks-=pq.top();
                pq.pop();
            }

            if( bricks<0 ){
                return i-1; 
            }
        }
        
        return n - 1;
    }
};