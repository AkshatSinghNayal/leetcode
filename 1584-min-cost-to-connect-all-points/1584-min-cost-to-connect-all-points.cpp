class Disjoint{
    public:
    vector<int>size , parent; 
    
    Disjoint(int V ){
        size.resize(V+1); parent.resize(V+1);

        for(int i = 0 ; i<= V ;i++ ){
            parent[i] = i ; 
        }
    }

    int findParent( int u ){
        if( u == parent[u]) return u;
        return parent[u] = findParent(parent[u]); 
    }

    void unionBySize( int u , int v ){
        int Pu = findParent(u);
        int Pv = findParent(v);

        if(size[Pu]>size[Pv]){
            size[Pu]+=size[Pv]; 
            parent[Pv] = Pu;
        }
        else{
            size[Pv] +=size[Pu]; 
            parent[Pu] = Pv;
        }
    }

}; 



class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<tuple<int,int,int>>nums;
        int n = points.size(); 
        Disjoint d(n);
        for(int i  = 0 ;i<n ;i++ ){
            for(int j = i+1; j<n ; j++ ){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]); 
                nums.push_back({dist, i, j});
            }
        }
        sort(nums.begin() , nums.end());

        int ans = 0 ; 

        for(auto& it : nums ){
            auto [ dist , i , j ] = it;
            
            if(d.findParent(i) != d.findParent(j)){
                ans+=dist;
                d.unionBySize(i,j);
            }


        }
        return ans;
    }
};