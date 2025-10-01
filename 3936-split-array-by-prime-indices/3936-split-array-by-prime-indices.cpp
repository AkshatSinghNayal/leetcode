class Solution {
public:

    bool isPrime( int temp ) {
        if( temp <= 1) return false ; 
        int i = 2 ; 
        for( i ; i*i<=temp ; i++){
            if(temp%i == 0 ) return false ;
        }
        return true ;
    }

    long long splitArray(vector<int>& nums) {
        long long sum1 = 0 ; 
        long long sum2= 0 ; 
        for(  int i = 0; i<nums.size() ; i++){
            if(isPrime(i )){
                sum1+=nums[i]; 
            }
            else{
                sum2+=nums[i]; 
            }
        }
        sum1= abs( sum1-sum2); 
        return sum1  ; 
    }
};