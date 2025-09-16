class Solution {
public:
        const int MOD = 1e9 + 7;
    long long power(long long x, long long n, long long mod) {
    long long result = 1;
    x %= mod;
    while (n > 0) {
        if (n & 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return result;
}


    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n - even;
        long long even1 = power(5, even , MOD);
        long long odd1 = power(4, odd , MOD);
        return (even1*odd1)%MOD;
    }
};