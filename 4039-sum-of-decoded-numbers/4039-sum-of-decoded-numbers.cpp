class Solution {
public:

    long long binpow(long long a, long long b, long long MOD) {
    long long ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

    int sumDecoded(vector<long long>& nums) {
        const long long MOD = 1e9+7;
        long long ans = 0 ; 
        
        for(auto& it : nums ){
            long long width = it%10; 
            long long d = it/10;

            int no_of_digit = 0; 
            long long temp = it/10; 
            while(temp){
                no_of_digit++; 
                temp/=10;
            }


            long long p1 = 1;
            for (int i = 0; i < no_of_digit - width; i++)
                p1 *= 10;

            long long x = (d / p1) % MOD;
            long long y = (d % p1) % MOD;
           


            ans = (ans+ (binpow(x , y , MOD))%MOD)%MOD;
        }
        return (int)ans; 
    }
};