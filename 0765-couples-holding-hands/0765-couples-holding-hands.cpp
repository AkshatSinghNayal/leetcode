class DSU{
    public:
    vector<int>parent;

    DSU(int v){
        parent.resize(v+1); 

        for(int i  = 0 ;i<=v;i++ ){
            parent[i] =i; 
        }
    }

    int find(int u){
        return parent[u]; 
    }

    void unionBySize( int u , int v ){
    
        parent[v] = u;
        parent[u] = v;

    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(); 
        DSU d(n);

        unordered_map<int,int>mp; 
        for(int i  = 0; i<n-1; i+=2){
            mp[i] = i+1;
            mp[i+1]= i;
            d.unionBySize(row[i],row[i+1]);
        }

        int swap = 0;

        for(int i = 0 ;i<n ;i++ ){
           int pi = d.find(row[i]); 
           cout<< pi << " " ; 
           if(mp[row[i]] == pi  ) continue;
           else{
                int temp = mp[row[i]]; 
                int ptemp = d.find(temp);
                // cout<<temp << " ";
                swap++;
                d.unionBySize(row[i],temp);
                d.unionBySize(pi,ptemp);
           }
        }
        return swap;
    }
};