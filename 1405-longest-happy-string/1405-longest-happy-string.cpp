class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = ""; 
        priority_queue<pair<int,char>>pq;
        if(a) pq.push({a, 'a'}); 
        if(b) pq.push({b , 'b'}) ;
        if(c) pq.push({c , 'c'}); 

        while(!pq.empty()){
            auto [ freq , ch1] =  pq.top() ; pq.pop(); 
            
            if(result.empty()){
                int temp = min(2 , freq); 
                freq-=temp; 
                result+=string(temp, ch1);
            }

            if(!result.empty()){
                if(result.back() == ch1){
                    if(pq.empty()) break; 
                auto [freq2 , ch2] = pq.top(); pq.pop(); 
                int temp = min(1 , freq2) ; 
                result+= string(temp ,ch2 ); 
                freq2-=temp; 
                if(freq2>0) pq.push({freq2,ch2}); 
                }
                else{
                    int temp = min(2,freq); 
                    result+=string(temp ,ch1); 
                    freq-=temp; 
                }
            }
            
            if(freq>0) pq.push({freq,ch1}); 

        }
        return result;
    }
};