class Solution {
public:
    int largestInteger(int num) {
        
        int temp = num; 
       string s=  to_string(num);
       priority_queue<int> pq1; 
       priority_queue<int> pq2;

       while( temp ){
            int digit = temp%10; 
            if(digit&1){
                pq1.push(digit); 
            }
            else{
                pq2.push(digit); 
            }
            temp/=10;
       }
        int result  = 0 ; 

        for( int i  = 0; i<s.size() ; i++){
            if((s[i] - '0')&1){
                result = result*10+ pq1.top(); 
                pq1.pop(); 
            }
            else{
                result = result*10 + pq2.top(); 
                pq2.pop(); 
            }
        }

       return result ;
        


    }
};