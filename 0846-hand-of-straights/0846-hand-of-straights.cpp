class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if( n%g != 0 ) return false;
        priority_queue<int , vector<int> , greater<int>> pq(hand.begin() , hand.end()); 

        while(!pq.empty()){
            int last = INT_MIN ; 
            int tempG = 0; 
            queue<int>q; 
            while( !pq.empty() and tempG < g  ){
                auto top = pq.top() ; pq.pop(); 
                if( last  == INT_MIN ){
                    last = top; 
                    tempG++; 
                }
                else{
                    if( top-1 != last ){
                        q.push(top);
                    }
                    else{
                        tempG++;
                        last = top;
                    }
                }
            }
            if( tempG != g ) return false;
            while(!q.empty()){
                pq.push(q.front()); q.pop();
            }
        }
        return true;
    }
};