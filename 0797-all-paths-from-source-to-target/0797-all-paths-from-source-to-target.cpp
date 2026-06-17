class Solution {
public:

    void dfs(vector<vector<int>>& list,vector<vector<int>>&paths , vector<int>&temp, int target ){

        if( target == temp.back() ){
            paths.push_back(temp);
        }

        for(auto& it : list[temp.back()]){
            temp.push_back(it);
            dfs(list , paths , temp , target );
            temp.pop_back();

        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& list){
        vector<vector<int>>paths; vector<int>temp; 
        int n  = list.size(); 
        temp.push_back(0);
        dfs( list , paths , temp , n-1 ); 
        return paths;   
    }
};