class Solution {
public:
    int largestInteger(int n, int s) {
        if( n ==  1 and s > 9  ) return -1; 
        if( n ==2 and s > 18 ) return -1; 
        if( n  ==3  and s > 27 ) return -1; 
        if( n  == 4 and s> 36 ) return -1; 
        if( n  == 5  and s > 45 ) return -1;

        int temp = 0 , digit = n*10; 
        while( n and s>=9 ){
            temp = temp*10 + 9; 
            s-=9;
            n--;
        }

        while(n and s>=0){
            temp= temp*10 + s; 
            s = max(0,s-9); 
            n--; 
        } 
        
        return temp ;
               
    }
};