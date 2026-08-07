class DisjoinSet{
    public: 
    vector<int> size , parent; 
    DisjoinSet(int V ){
        parent.resize(V+1); 

        for(int i = 0 ;i<=V ;i++ ){
            parent[i] = i; 
        }
    }

    int find( int u){

        if( parent[u] == u ) return u ; 
        return parent[u] = find(parent[u]); 
    }

    void unionBySize( int u , int v ){
        int pa = find(u) , pb = find(v); 

        if( pa == pb ) return ;

        if( pa > pb ){
            swap(pa,pb); 
        }

        parent[pb] = pa ;

    }
    
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjoinSet d(26);

        for(int i = 0 ;i<s1.size() ;i++ ){
            d.unionBySize(s1[i]-'a' , s2[i]-'a'); 
        }

        string result=  ""; 

        for(auto& it : baseStr ){
            char par = d.parent[d.find(it-'a')]+'a' ; 
            result+=par;
        }
        return result;
    }
};