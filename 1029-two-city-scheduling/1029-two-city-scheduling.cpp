class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin() , costs.end() , [&](auto const& a , auto const& b ){
            return (a[0]-a[1]) < (b[0]-b[1]); 
        }); 

        int n = costs.size();
        int cost = 0 ;

        for(int i  = 0 ;i<n/2 ; i++ ){
            cost+=costs[i][0]; 
            cout<< i << "->" ; 
        }
        for(int i = n/2; i<n; i++ ){
            cost+=costs[i][1]; 
            cout<< i << "<-" ; 

        }

        return cost;

    }
};