class Solution {
public:

    vector<int> solve(unordered_map<int,vector<int>>&items, vector<int>&indOfItems){
        vector<int>temp; 

        queue<int>q; 
        for(int i = 0 ;i<indOfItems.size() ; i++ ){
            if(indOfItems[i] == 0 ) q.push(i); 
        }

        while(!q.empty()){
            auto idx = q.front(); q.pop(); 
            temp.push_back(idx); 

            for(auto& it : items[idx]){
                indOfItems[it]--;
                if(indOfItems[it] == 0  ) q.push(it);
            }
        }

        if( temp.size() != indOfItems.size() ) temp.clear(); 
        return temp;

    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int,vector<int>>grup; 
        unordered_map<int,vector<int>>items; 
        // unordered_map<int,vector<int>>mp;
        vector<int>indOfItems(n);
        vector<int>grp(n);

        for(int i  = 0 ;i<n ; i++ ){
            if( group[i] == -1 ){
                grp[i]=m++; 
            }
            else{
                grp[i] = group[i]; 
            }
        }
        vector<int>indOfGrp(m); 

        for(int i  = 0 ;i<n ;i++ ){
            for(auto& it : beforeItems[i]){
                if(beforeItems[i].size() == 0 ) continue; 

                items[it].push_back(i); 
                indOfItems[i]++; 

                if(grp[it] != grp[i]){
                    // cout<<grp[it] << "=====" << grp[i] << endl;
                    grup[grp[it]].push_back(grp[i]); 
                    indOfGrp[grp[i]]++; 
                }
            }
        }

        vector<int>resultOfItems = solve(items,indOfItems); 
        vector<int>resultOfGrp = solve(grup , indOfGrp ); 

        // cout<<"result "; 
        // for(auto& it : resultOfItems ) cout<<it << " ";
        // cout<<endl;
        // cout<<"grp ";
        // for(auto& it : resultOfGrp ) cout<<it<< " ";

        vector<int>done; 

        // for(int i  = 0 ;i<n; i++ ){
        //     mp[grp[i]].push_back(i); 
        // }
        

        unordered_map<int,vector<int>>mp; 

        for(auto& it : resultOfItems ){
            mp[grp[it]].push_back(it); 
        }

        for(auto& it : resultOfGrp ){
            for(auto& temp : mp[it] ){
                done.push_back(temp);
            }
        }

    
        return done;
    }
};