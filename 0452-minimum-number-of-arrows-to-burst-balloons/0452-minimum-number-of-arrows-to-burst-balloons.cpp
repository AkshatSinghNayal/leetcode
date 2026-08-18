class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end()); 
        int count = 0; 
        
        int n = points.size(); int i = 0; 
        while(i < n ){
            int start = points[i][0] , end = points[i][1]; 
            int index = i+1; 
            

            while( index < n and start <= points[index][0] and points[index][0] <= end  ){
                start = max(start , points[index][0]) , end = min( points[index][1] , end ); 
                index++; 
            }
            i = index; 
            count++; 
        }
        return count;
    }
};