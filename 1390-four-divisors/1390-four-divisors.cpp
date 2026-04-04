class Solution {
public:

    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
    }       

    int sumFourDivisors(vector<int>& nums) {
    int sum = 0; 

        for(auto& it : nums ){
            int count = 2; 
            if(isPrime(it)) continue;
            int temp = 1+it; 

            for( int i = 2; i*i<=it ; i++   ){
                if( it%i == 0 ){
                    count++; 
                    temp+=i;
                    if( i!=(it/i)){
                        count++;
                        temp+=(it/i);
                    }
                }

                if(count >4 ) break;
            }
            if(count == 4 ) sum+=temp;

        }

        return sum;
    }
};