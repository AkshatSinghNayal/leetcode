class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for( auto& it : nums ){
            for(int i =2 ; i*i<=it ; i++){
                int temp =  round(cbrt(it)); 
                if( temp*temp*temp == it and isPrime(temp)){
                    ans += 1+ temp + temp*temp + it; 
                    break; 
                }
                else{
                    if( it% i  == 0 ){
                        int anotherOfI = it/i; 
                        if( i!= anotherOfI and isPrime( i ) and isPrime(anotherOfI)){
                            ans+=1 + i + anotherOfI + it ; 
                            break; 
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
