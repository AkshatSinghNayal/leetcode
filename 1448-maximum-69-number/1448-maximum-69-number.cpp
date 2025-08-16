class Solution {
public:
    int maximum69Number (int num) {
        int temp = num ; 
        int position =1 ; 
        int current = 0 ;
        while(temp){
            if(temp%10 == 6){
                current = position;
            }
            temp=temp/10;
            position = position*10;
        }
        
        return num + (3*current);
    }
};