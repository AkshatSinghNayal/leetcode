class Solution {
public:

    class comp{
    public:
        bool operator()(const pair<int,int>& a , const pair<int,int>& b ){
            if( a.first == b.first ){
                return a.second > b.second ; 
            }
            return a.first > b.first ;
        }
    }; 

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n  = costs.size();
        int idx1 = 0 , idx2 = n-1; 
        long long cost = 0; 
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq1, pq2;

        while(idx1 < n && pq1.size() < candidates){
            pq1.push({costs[idx1], idx1}); 
            idx1++;
        }
        while(idx2 >= idx1 && pq2.size() < candidates){
            pq2.push({costs[idx2], idx2}); 
            idx2--;
        }

        while(k > 0){
    
    if(!pq1.empty() && !pq2.empty()){
        
        if( (pq1.top().first < pq2.top().first) || 
            (pq1.top().first == pq2.top().first && pq1.top().second < pq2.top().second) ){

            cost += (long long)pq1.top().first;
            pq1.pop();

            // ✅ refill LEFT only
            if(idx1 <= idx2){
                pq1.push({costs[idx1], idx1});
                idx1++;
            }
        }
        else{
            cost += (long long)pq2.top().first;
            pq2.pop();

            // ✅ refill RIGHT only
            if(idx1 <= idx2){
                pq2.push({costs[idx2], idx2});
                idx2--;
            }
        }
    }
    else if(!pq1.empty()){  // only left remains
        cost += (long long)pq1.top().first;
        pq1.pop();

        if(idx1 <= idx2){
            pq1.push({costs[idx1], idx1});
            idx1++;
        }
    }
    else{  // only right remains
        cost += (long long)pq2.top().first;
        pq2.pop();

        if(idx1 <= idx2){
            pq2.push({costs[idx2], idx2});
            idx2--;
        }
    }

    k--;
}

        return cost;
    }
};