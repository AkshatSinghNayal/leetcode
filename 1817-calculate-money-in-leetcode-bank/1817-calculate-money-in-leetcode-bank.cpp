class Solution {
public:
    int totalMoney(int n) {
        int week = n/7; 
        int days = n%7 ; 
        int totalMoney = 0 ; 

        for( int i  = 0; i<week ; i++){
            totalMoney+= 28 + 7*i ; 
        }
        int extra = 0; 
        for( int i  = 0 ; i<days ; i++){
            extra+=( i+ week + 1); 
        }
        return extra+totalMoney ; 
    }
};