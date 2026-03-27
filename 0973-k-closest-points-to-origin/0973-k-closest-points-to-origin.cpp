class Solution {
public:

    class comp{
        public:
        bool operator()(const vector<int>& a , const vector<int>& b ){
            int a1 = a[0]*a[0] +a[1]*a[1]; 
            int b1 = b[0]*b[0] + b[1]*b[1]; 

            return a1<b1;

        }
    }; 

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort( points.begin(), points.end(),comp());

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};