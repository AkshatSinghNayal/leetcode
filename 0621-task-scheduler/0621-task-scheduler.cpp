class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int operations = 0; 
        for(auto& it : tasks)mp[it]++; 
        priority_queue<pair<int,char> , vector<pair<int,char>>>pq;
        for(auto& it : mp ) pq.push({it.second,it.first});

        while(!pq.empty()){
            mp.clear();
            int temp = n+1 , tempo =0 ;
            while(temp-- and !pq.empty()){
                auto [freq , ch ] = pq.top() ; pq.pop();
                if(freq>0){
                    tempo++; 
                    freq--; 
                    mp[ch] = freq;
                }
            }
            for(auto& it : mp ){
                if( it.second >0 ) pq.push({it.second , it.first}); 
            }
            if(!pq.empty()) operations+=n+1;
            else operations+=tempo;
        }
        return operations;
    }
};