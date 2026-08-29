class Disjoint{
    public:
    vector<int> parent; 
    
    Disjoint(int V ){
        parent.resize(V+1);

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
        
        if( Pu  == Pv ) return;

        if(Pu > Pv){
            parent[Pu] = Pv;
        }
        else{
            parent[Pv] = Pu;
        }

    }

}; 



class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjoint d(26);
        int n =  s1.size(); 
        for(int i  = 0 ;i<n; i++ ){
            int u = s1[i]-'a'; 
            int v = s2[i]-'a'; 

            d.unionBySize( u , v );
        }

        string result ="";

        for(auto& it : baseStr ){
            int p = d.findParent(it-'a'); 
            result+=d.parent[p]+'a'; 
        }

        return result;
    }
};