class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0 ; 
        if( num == 0 ) return num ; 
        while(num>0 ){
            if(num%2 !=0 ){
                count++; 
                num--; 
            }
            count++; 
            num/=2 ; 


        }
        return count-1 ;
    }
};