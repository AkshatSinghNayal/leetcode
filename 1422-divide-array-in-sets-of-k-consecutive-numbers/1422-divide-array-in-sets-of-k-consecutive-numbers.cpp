class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        unordered_map<int , int > freq ; 
        for( auto it : hand ){
            freq[it]++; 
        }
        priority_queue<int , vector<int> , greater<int> > pq ; 
        for( auto it : freq ){
            pq.push(it.first);
        }
        while(!pq.empty()){
            auto top = pq.top() ; pq.pop() ; 
            if(freq[top] == 0 ) continue ; 
            int fq = freq[top] ; 
            for(int i = 0 ; i<groupSize ; i++){
                if( freq[top+i] >= fq ){
                    freq[top+i]-=fq ; 
                }
                else{
                    return false ; 
                }
            }

        }
        return true; 
  
    }
};