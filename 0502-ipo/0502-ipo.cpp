class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq; // store max profit 
        vector<pair<int,int>>arr;
        int i =0 ,n =profits.size(); 
        while(i<n){
            arr.push_back({ capital[i] , profits[i]});
            i++;
        }
        sort(arr.begin(),arr.end() ,[&](auto a , auto b){
            if( a.first == b.first){
                return a.first > b.first ; 
            }
            return a.first < b.first;
        }); 
        
        i = 0; 
        while(  k> 0){
            bool found = false;
            while( i< n and arr[i].first <= w ){
                pq.push(arr[i].second );
                i++;
                found = true;
            }
            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
                k--;
            }
            if(!found && pq.empty()) break;
        }
        

        return w;
    }
};