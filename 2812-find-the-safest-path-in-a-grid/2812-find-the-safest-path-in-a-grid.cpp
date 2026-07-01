class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return 0;
        queue<pair<int,int>>q;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>min_dist(row,vector<int>(col,INT_MAX));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1) 
                {
                    q.push({i,j});
                    min_dist[i][j]=0;
                }
            }
        }
        vector<int>dx{-1,0,1,0};
        vector<int>dy{0,1,0,-1};
        while(!q.empty())
        {
            auto front=q.front();
            q.pop();
            int x=front.first;
            int y=front.second;
            for(int i=0;i<4;i++)
            {
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newY>=0 && newX<row && newY<col)
                {
                    int newDist=1+min_dist[x][y];
                    if(newDist<min_dist[newX][newY])
                    {
                        min_dist[newX][newY]=newDist;
                        q.push({newX,newY});
                    }
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int> >path_safeness(row,vector<int>(col,-1));
        path_safeness[0][0]=min_dist[0][0];
        pq.push({path_safeness[0][0],{0,0}});
        while(!pq.empty())
        {
            auto topNode=pq.top();
            int topDist=topNode.first;
            int x=topNode.second.first;
            int y=topNode.second.second;
            pq.pop();
            if(x==row-1 && y==col-1) return topDist;
            for(int i=0;i<4;i++)
            {
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newY>=0 && newX<row && newY<col)
                {
                    int newPathSafeness=min(min_dist[newX][newY],topDist);
                    if(newPathSafeness>path_safeness[newX][newY])
                    {
                        path_safeness[newX][newY]=newPathSafeness;
                        pq.push({newPathSafeness,{newX,newY}});
                    }
                }
            }
        }
        return -1;
    }
};