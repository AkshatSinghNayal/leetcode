class Solution {
public:

    class comp{
    public:
        bool operator()(const pair<int,char>& a , const pair<int,char>& b ){
            return a.first < b.first;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        if(n == 0) return size;

        int operation = 0; 
        priority_queue<pair<int,char>, vector<pair<int,char>>, comp> pq;  
        unordered_map<char,int> mp; 

        for(auto& it : tasks) mp[it]++; 
        for(auto& it : mp) pq.push({it.second ,it.first}); 
        mp.clear();
        while(!pq.empty()){
            int temp = 0;
            int tempo = n + 1;

            mp.clear(); // ✅ IMPORTANT FIX

            while(tempo-- && !pq.empty()){
                auto [freq, ch] = pq.top(); pq.pop();
                temp++;
                freq--;
                if(freq > 0) mp[ch] = freq;

            }

            for(auto& it : mp){
                pq.push({it.second, it.first});
            }

            if(!pq.empty()) operation += (n + 1);
            else operation += temp;
        }

        return operation;
    }
};