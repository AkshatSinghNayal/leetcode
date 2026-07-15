class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long eSum = 0 , oSum = 0;
        for(int i  = 1 ;i<=n*2;i++ ){
            if(1&i){
                oSum+=i;
            }
            else{
                eSum+=i;
            }
        } 
        return gcd(eSum,oSum);
    }
};