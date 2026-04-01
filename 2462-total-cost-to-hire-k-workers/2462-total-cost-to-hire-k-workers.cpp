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
        priority_queue<pair<int,int>, vector<pair<int,int>> , comp> left , right; 
        int i = 0 , n= costs.size() , j = n-1; 
        long long cost = 0;
        while( i <= j and left.size() < candidates){
            left.push({costs[i],i}); 
            i++; 
        }
        while(i <= j and right.size() < candidates ){
            right.push({costs[j] , j});
            j--;
        }

        while( k-- ){
            if( !left.empty() and !right.empty()){
                if(  (left.top().first < right.top().first) or ( left.top().first == right.top().first and left.top().second < right.top().second )   ){
                cost+=(long long)left.top().first;
                // cout << left.top().first << " left " ; 

                left.pop();

                if( i<=j ){
                    left.push({costs[i],i}); 
                    i++; 
                }
            }
            else{
                cost+=(long long)right.top().first;
                // cout << right.top().first << " right " ; 

                right.pop();

                if( i<=j ){
                    right.push({costs[j],j}); 
                    j--; 
                }
            }
            }
            else{
                if( left.empty() and !right.empty()){
                cost+=(long long)right.top().first;
                right.pop();
            }
            if( right.empty() and !left.empty()){
                cost+=(long long)left.top().first;
                left.pop();
            }
            }

            

        }
        return cost;
    }
};