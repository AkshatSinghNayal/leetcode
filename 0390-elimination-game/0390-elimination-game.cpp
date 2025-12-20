class Solution {
public:
    int lastRemaining(int n) {
        long long gap = 1 , rem = n , last =  1 ; 
        bool left = true; 
        while( rem > 1 ){
            if( left == false and (rem%2 == 0) ){
                rem/=2 ;
                gap*=2;
                left=!left;
                continue;
            }
            left=!left; 
            last = last+gap ;
            gap *=2 ; 
            rem/=2; 

        }
        return (int)last; 
    }
};