class Solution {
public:
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

    int solve( int num , int& sum , int count){
        
        for(int i = 2 ; i*i<=num ; i++){
            if( num% i == 0 ){
                if( num/i == i ){
                    sum+=i ; 
                    count+=1; 
                }
                else{
                    sum+=i; 
                    sum+=num/i; 
                    count+=2; 
                }
            }
            if( count>2 )return -1 ; 
        }
        return (count == 2) ? 2 : -1 ;
    }

    int sumFourDivisors(vector<int>& nums) {
        int n  = nums.size() ;
        long long globalCount =0; 
        for(int i = 0 ; i<n ; i++){
        int sum = 0 ; 
            int number = nums[i]; int count = 0 ; 
            if( isPrime(number)){
                continue;
            }
            else{
                int count = solve( number , sum , 0); 
                if( count == 2 ){
                    globalCount = globalCount+1+number+sum; 
                }
            }
            

        }
        return globalCount;
    }
};