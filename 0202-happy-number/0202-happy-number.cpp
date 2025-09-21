class Solution {
public:

    long long helper( int n ){
        long long tracker = 0 ; 
        int temp = n ; 
        while(temp!=0){
            int digit = temp%10 ; 
            int square = 1ll*digit*digit; 
            tracker+=square; 
            temp/=10;
        }
        return tracker ; 
    }

    bool happy(int n ){
        set<int>mp ; 

        int temp = n ; 
        
        long long sq = 0 ; 

        while(true){
            sq = helper( temp );
            if(mp.count(sq)) return false; 
            if( sq == 1) return true ; 
            mp.insert(sq);
            temp = sq ; 
        }

        return true; 
    }

    bool isHappy(int n) {
       
        return happy(n ) ; 
    }
};