class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char , int> mp ; 
        n=n+1; 
        int operations = 0 ; 
        for(auto& it  : tasks){
            mp[it]++; 
        }

        priority_queue<pair<int,char> , vector<pair<int,char>> , less<pair<int, char>>>pq ;

        for(auto& [key , freq] : mp ){
            pq.push( {freq , key }); 
        }

        while( !pq.empty() ){
            int temp =  0;
            queue<pair<int,char>>q; 
            while(!pq.empty() and temp < n  ){
                auto [ freq , ch ]  = pq.top(); pq.pop();
                freq--;
                if( freq ){
                    q.push({ freq , ch});
                }
                temp++;
            }
            if( !q.empty() ) operations = operations + (temp+( n - temp )); 
            else operations += temp ;


            while( !q.empty() ){
                pq.push({ q.front().first , q.front().second}); 
                q.pop(); 
            }
        }
        return operations ;
    }
};