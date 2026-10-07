class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>ans(n);
        vector<int>ind(n,0); 
        unordered_map<int,vector<int>>mp;
        queue<int>q;

        for(int i  = 0;i<richer.size() ; i++ ){
            ind[richer[i][1]]++;
            mp[richer[i][0]].push_back(richer[i][1]); 
        }

        for(int i =0;i<ind.size();i++ ){
            if(ind[i] == 0 ){
                q.push(i);
            }
            ans[i]=i;
        }

        while(!q.empty()){
            auto node = q.front(); q.pop();
            // cout<< node << " ";
            
            for(auto& it : mp[node]){
                ind[it]--;
                // cout<< it << " "; 
                if( quiet[ans[it]] >= quiet[ans[node]] ){
                    ans[it] = ans[node];
                }
                if(ind[it] == 0 ) q.push(it);
            }

        }
        return ans;
    }
};