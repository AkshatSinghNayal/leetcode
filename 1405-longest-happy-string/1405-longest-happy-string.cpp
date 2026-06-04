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
            int n = result.size(); 

            if( n>=2 and result[n-1] == ch1 and result[n-2] == ch1 ){
                if( pq.empty() ) break;
                auto [freq2 , ch2] = pq.top(); pq.pop(); 
                result+=ch2; 
                freq2-=1; 
                if(freq2>0) pq.push({freq2 , ch2});
                if(freq >0 ) pq.push({freq, ch1}); 
            }
            else{
                result+=ch1;
                freq-=1; 
                if(freq>0) pq.push({freq,ch1}); 
            }

        }
        return result;
    }
};