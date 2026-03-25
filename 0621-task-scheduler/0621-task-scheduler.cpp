class Solution {
public:

    class comp{
        public :
        bool operator()(const pair<int,char>& a , const pair<int,char>& b ){
            return a.first < b.first;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int operation = 0; 
        priority_queue<pair<int,char> , vector<pair<int,char>> , comp>pq;  
        unordered_map<char,int>mp; 
        for(auto& it : tasks) mp[it]++; 
        for(auto& it : mp ) pq.push({it.second ,it.first}); 

        while(!pq.empty()){
    int temp = 0;
    int tempo = n + 1; // ✅ n+1 not n
    mp.clear();        // ✅ clear stale frequencies each cycle
    
    while(tempo-- && !pq.empty()){
        auto [freq, ch] = pq.top(); pq.pop();
        temp++;
        freq--;
        if(freq > 0) mp[ch] = freq; // ✅ only store remaining
    }
    
    for(auto& it : mp){
        pq.push({it.second, it.first});
    }
    
    if(!pq.empty()) operation += (n+1);
    else operation += temp;
}

        return operation;

    }
};