class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        set<tuple<int,int,string>> st; // FIX 1
        int countKey = 0;
        int starti = 0, startj = 0;
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = grid[i][j];
                if(ch >= 'a' and ch <= 'f') countKey++;
                else if(ch == '@'){
                    starti = i;
                    startj = j;
                }
            }
        }

        vector<pair<int,int>> dis = {{1,0},{0,1},{-1,0},{0,-1}};

        priority_queue<
            tuple<int,int,int,string>,
            vector<tuple<int,int,int,string>>,
            greater<tuple<int,int,int,string>>
        > pq;

        pq.push({0,starti,startj,""});

        while(!pq.empty()){
            auto [dist,row,col,key] = pq.top();
            pq.pop();

            // FIX 2: Track position + keys
            if(st.count({row,col,key})) continue;
            st.insert({row,col,key});

            if((int)key.size() == countKey){
                return dist;
            }

            for(auto& it : dis){
                int nr = row + it.first;
                int nc = col + it.second;

                // FIX 3: Remove incorrect visited checks
                if(nr < 0 or nc < 0 or nr >= n or nc >= m
                   or grid[nr][nc] == '#') continue;

                if(grid[nr][nc] >= 'A' and grid[nr][nc] <= 'F'){
                    char ch = tolower(grid[nr][nc]);

                    if(key.find(ch) == string::npos) continue;
                    else{
                        pq.push({dist+1,nr,nc,key});
                    }
                }
                else{
                    char ch = grid[nr][nc];

                    if(ch == '.' or ch == '@'){
                        pq.push({dist+1,nr,nc,key});
                    }
                    else{
                        string temp = key;
                        temp = (key.find(ch) != string::npos)
                               ? temp : temp+ch;

                        // FIX 4: Normalize key order
                        sort(temp.begin(), temp.end());

                        pq.push({dist+1,nr,nc,temp});
                    }
                }
            }
        }
        return -1;
    }
};