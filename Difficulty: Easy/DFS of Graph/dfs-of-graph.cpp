class Solution {
  public:
    
    void solve( int index ,  vector<int>& ans , vector<int>& ddfs,vector<vector<int>>& adj ){
        
        if( ans[index] != 0 )return ; 
                ans[index] = 1; 
        for( int i  = 0 ; i< adj[index].size() ; i++ ){
            
               if( ans[adj[index][i]] == 0) {
                   ddfs.push_back(adj[index][i]); 
                   solve(adj[index][i] , ans , ddfs , adj ); 
               }
            
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size(); 
        vector<int> ans(n+1 , 0);
        vector<int> ddfs; 
        ddfs.push_back(0); 
        
        
        for(int i =0; i<n ; i++){
            if( ans[i]== 0 ){
                solve( i , ans , ddfs ,adj ) ; 
            }
        }
        return ddfs ;
    }
};