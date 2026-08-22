class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0  , product = 1; 
        int temp = n ; 
        while(temp){
            sum+=temp%10;
            product*=temp%10;
            temp/=10;
        }
        return ( n%(sum+product) == 0);
    }
};