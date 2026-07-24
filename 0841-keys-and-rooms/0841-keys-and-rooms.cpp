class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size(); 
        vector<vector<int>>list(V);
        vector<int>vis(V,-1); 

        for(int i = 0; i<V; i++ ){
            for(int j = 0 ;j<rooms[i].size();j++ ){
                if( i != rooms[i][j]) {
                    cout<<rooms[i][j]<< " "; 
                    list[i].push_back(rooms[i][j]);
                }
            }
        }

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            auto node = q.front(); q.pop();

            
            vis[node] = 1;

            for(auto& it : list[node]){
                if(vis[it] == -1 ){
                    q.push(it);
                }
            }
        }

        for(auto& it : vis ) {
            if( it == -1 ) return false;
        }

        return  true;
    }
};