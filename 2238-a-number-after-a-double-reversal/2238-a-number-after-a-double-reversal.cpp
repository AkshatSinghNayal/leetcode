class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(  num == 0 ) return true ; 
        int temp = num ; 
        int digit ; 
        while( temp!=0 ){
             digit = temp; 
            temp/=10 ; 
        }

        if((num%10 == 0) && (num%10 != digit)) return false ; 
        return true ;
    }
};