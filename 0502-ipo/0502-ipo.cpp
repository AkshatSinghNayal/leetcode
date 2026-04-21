class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        vector<pair<int,int>>temp; 
        priority_queue<int>pq;
        for(int i = 0 ;i< n ;i++ ){
           temp.push_back({capital[i] , profits[i]}); 
        }
        sort(temp.begin() , temp.end());
        int i = 0 ; 
        while( i< n and k>0 ){
            while( i< n and  w>= temp[i].first ){
                pq.push(temp[i].second); 
                i++; 
            }

            if(!pq.empty() and k>0 ){
                w+=pq.top(); 
                pq.pop(); 
                k--;
            }
            else {
                break;
            }
        }
        while(k>0 and !pq.empty()){
            w+=pq.top(); pq.pop(); 
            k--;
        }
        return w;
    }
};