class Solution {
public:
    int lastRemaining(int n) {
        bool left = true;
        int size = n; int head = 1 , gap =1 ;
        while(size>1){
            cout<<head<< " " ; 
            if( left or !left and size % 2 != 0 ){
                head+=gap;
            }
            gap*=2;
            size/=2; 
            left =!left;
        }
        return head;
    }
};