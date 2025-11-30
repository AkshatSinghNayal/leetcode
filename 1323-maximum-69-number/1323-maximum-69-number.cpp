class Solution {
public:
    int maximum69Number (int num) {
        int temp =  num ; 
        int position = 1; 
        int assume = 0; 

        while( temp ){
            if( temp%10 == 6 ){
                assume = position ; 
            }
            temp/=10 ;
            position  = position*10; 
        }
        return num+( assume*3 ) ; 
    }
};