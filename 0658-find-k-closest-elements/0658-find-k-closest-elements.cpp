class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , less<pair<int,int>>>pq;
        int i =0;
        int n  = arr.size();
        while(i < k ){
            pq.push({ abs(x-arr[i]), arr[i]});
            i++;
        }
        while( i< n ){
            if( pq.top().first > abs(x - arr[i]) ){
                pq.pop();
                pq.push( {abs(x-arr[i]) , arr[i]});
            }
            i++;
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back( pq.top().second );
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};