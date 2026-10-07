class DSU{
    public:
    vector<int>parent,size;
    vector<pair<int,int>>ans;

    DSU( int v ){
        parent.resize(v+1); 
        size.resize(v+1,1);

        for(int i  = 0 ; i<=v ;i++ ){
            parent[i] = i ;
        }
    }
    int find( int u ){
        if( parent[u] == u ) return u ; 
        return parent[u] = find(parent[u]); 
    }

    void unite( int u , int v ){
        int pu = find(u); 
        int pv = find(v); 

        if( pu == pv ) {
            ans.push_back({u,v});
            return;
        }

        if( size[pu] >= size[pv]){
            size[pu]+=size[pv]; 
            parent[pv] = pu; 
        }
        else{
            size[pv]+=size[pu]; 
            parent[pu] = pv;
        }
    }
};

class Solution {
public:

    bool topo(int from, vector<int>&indegree, queue<int>q , unordered_map<int,vector<int>>&mp, int digit,int n){
        while(!q.empty()){
            auto node = q.front() ; q.pop();
            // cout<<node<<" ";
            n--;
            for(auto& it: mp[node]){
                if(node == from and digit == it ) continue;
                indegree[it]--;
                if( indegree[it] == 0 ) q.push(it);
            }
        }
        return n == 0;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);
        vector<int>indegree(n+1);
        bool flag = false;
        unordered_map<int,vector<int>>mp;
        unordered_map<int,vector<int>>fromy;


        for(auto& it : edges )   {
            int a = it[0] , b = it[1];   
            indegree[b]++;
            mp[a].push_back(b);
            fromy[b].push_back(a);
            d.unite( a, b );
        }

        queue<int>q;
        int digit = 0;

        for(int i =1 ;i<=n ;i++ ){
            if( indegree[i] == 2 ){
                flag = true;
                digit=i;
            }
            if( indegree[i] == 0 ) q.push(i);
        }
        // cout<<digit<<"<->"<<endl;
        int first =-1 , second =-1;
        if(!flag){
            int size = d.ans.size();
            vector<int>ok;
            ok.push_back(d.ans[size-1].first);
            ok.push_back(d.ans[size-1].second);
            return ok;
        }
        else{
            for(int i = 0 ; i<fromy[digit].size(); i++ ){
                indegree[digit] =1; 
                vector<int>temp= indegree;
                int from = fromy[digit][i];
                // cout<< from << "->"<<q.size()<<" ";
                if(topo(from, temp,q,mp,digit,n)){
                    first = from;
                    second = digit;
                }
                
            }
        }
        return {first,second};
    }
};