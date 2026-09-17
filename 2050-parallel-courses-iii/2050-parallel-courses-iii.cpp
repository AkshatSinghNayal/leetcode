class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>price(n+1); 
        for(int i  = 1 ;i<=n ;i++ ){
            price[i] = time[i-1];   
        }
        
        unordered_map<int,vector<int>>mp;
        unordered_map<int,vector<int>>mp1; 
        vector<int>indegree(n+1);

        for(auto&it: relations){
            mp[it[0]].push_back(it[1]); 
            mp1[it[1]].push_back(it[0]); 
            indegree[it[1]]++;
        }
        int cost = 0 ; 
        queue<int>q; 

        for(int i = 1 ;i<indegree.size(); i++ ){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto idx=q.front(); q.pop(); 
            for(auto& it : mp[idx]){
                indegree[it]--; 
                if(indegree[it] == 0  ){
                    q.push(it);
                    int maxi = INT_MIN;
                    for(auto& temp: mp1[it]){
                        maxi = max(maxi , price[temp]);
                    }
                    price[it] += maxi;
                   
                }
            }
        }


        return *max_element(price.begin(),price.end());
    }
};