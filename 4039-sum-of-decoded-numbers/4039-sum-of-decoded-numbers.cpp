class Solution {
public:
    long long binpow(long long x, long long y, long long mod) {
        long long ans = 1;

        while (y > 0) {
            if (y & 1)
                ans = ans * x % mod;

            x = x * x % mod;
            y >>= 1;
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;

        for (auto num : nums) {
            long long width = num % 10;
            long long d = num / 10;

            long long integ = d;
            long long countdig = 0;

            while (integ > 0) {
                integ /= 10;
                countdig++;
            }

            long long p = 1;

            for (int i = 0; i < countdig - width; i++) {
                p *= 10;
            }

            long long x = d / p;
            long long y = d - x * p;

            long long add = binpow(x, y, MOD);

            ans = (ans + add) % MOD;
        }

        return ans;
    }
};