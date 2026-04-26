class Solution {
public:

    vector<pair<int,int>> dist = {{-1,0},{1,0},{0,-1},{0,1}}; 

    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int n , int m , int original , vector<vector<int>>&vis){
        vis[sr][sc] =1;
        image[sr][sc] = color; 
     

        for(auto& it : dist ){
            int newRow =  it.first+sr; 
            int newCol = it.second+sc; 

            if(newRow <n and newRow >=0 and newCol>=0 and newCol<m and image[newRow][newCol] == original and vis[newRow][newCol] == -1 ){
                dfs(image , newRow , newCol ,  color ,  n ,  m ,  original , vis); 
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size() , m = image[0].size(); 
        int original = image[sr][sc]; 
        vector<vector<int>>vis(n , vector<int>(m , -1)); 
        dfs( image , sr , sc , color, n , m , original , vis ); 
        return image; 

    }
};