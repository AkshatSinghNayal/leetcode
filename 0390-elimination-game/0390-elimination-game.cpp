class Solution {
public:
    int lastRemaining(int n) {
        if( n ==1 ) return 1;
        int gap = 1 , head = 1 , rem = n ; 
        bool left = true; 

        while(rem>1){
            if( (left == false and rem %2 != 0) or left == true  ){
                // change head
                head+=gap; 
            }
            rem/=2;
            gap*=2;
            left = !left;

        }
    return head;
    }
};