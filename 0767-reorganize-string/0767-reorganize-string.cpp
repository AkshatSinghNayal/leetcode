class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp; 
        string result = ""; 
        priority_queue<pair<int,char>>pq; 
        for(auto& it : s ){
            mp[it]++; 
        }

        for(auto& [ch , freq] : mp ){
            pq.push({freq , ch}); 
        }

        while(!pq.empty()){
            auto [freq , ch1] = pq.top(); pq.pop(); 
            int n  = result.size(); 

            if( n>=1 and result[n-1] == ch1 ){
                if(pq.empty()) return ""; 
                auto [freq2 , ch2 ] = pq.top(); pq.pop() ; 
                result+=ch2; 
                freq2-=1; 
                if(freq2) pq.push({freq2 ,ch2 }); 
                if(freq) pq.push({freq ,ch1}); 
            }
            else{
                result+=ch1; 
                freq-=1; 
                if(freq) pq.push({freq ,ch1}); 
            }
        }
        return result;
    }   
};