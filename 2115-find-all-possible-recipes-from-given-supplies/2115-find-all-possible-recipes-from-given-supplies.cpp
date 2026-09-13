class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string>st(supplies.begin(),supplies.end());
        unordered_map<string,vector<int>>mp;
        vector<int>indegree(recipes.size()); 
        vector<string>result;
        int n = recipes.size();
        queue<int>q;

        for(int i  = 0 ;i<recipes.size(); i++ ){
            for(auto& it : ingredients[i]){
                if(!st.count(it)){
                    mp[it].push_back(i);
                    indegree[i]++;
                }
            }
        }

        for(int i  = 0 ;  i< n ;i++ ){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }

        while(!q.empty()){
            int index = q.front(); q.pop(); 
            string temp = recipes[index]; 
            result.push_back(temp);

            for(auto& it : mp[temp]){
                indegree[it]--;
                if(indegree[it] == 0  ) q.push(it);
            }
        }   

        return result;

    }
};