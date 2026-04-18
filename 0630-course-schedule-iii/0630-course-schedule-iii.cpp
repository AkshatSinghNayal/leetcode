class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>>temp;
        for(auto& it : courses ){
            temp.push_back({it[1],it[0]}); 
        }
        sort(temp.begin(),temp.end());
        int maxi = 0 ; long long total = 0; 
        priority_queue<int>pq; 
        for(auto& it : temp ){
            total+=it.second;
            pq.push(it.second);

            while(!pq.empty() and total>it.first){
                total-=pq.top(); 
                pq.pop(); 
            }

            int size = pq.size();
            maxi = max(maxi,size); 
            
            
        } 
        return maxi;
    }
};