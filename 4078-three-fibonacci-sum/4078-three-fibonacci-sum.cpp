class Solution {
public:
    bool threeFibonacciSum(int n) {
        long long a = 0 , b = 1 , c =a+b;

        while(a+b+c<=n){
            if(a+b+c == n) return true;
            int temp = b; 
            b = a+b; 
            a = temp;
            c=a+b;
        }
        return false;
    }
};
