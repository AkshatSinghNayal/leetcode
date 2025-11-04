class Solution {
public:
    const int MOD = 1337;

    int modPow(int a, int k) {
        long long result = 1;
        long long x = a % MOD;
        while (k > 0) {
            if (k % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            k /= 2;
        }
        return (int)result;
    }

    int superPow(int a1, vector<int>& b) {
        int ans = 1;
        for (int digit : b) {
            // compute (ans^10 * a^digit) % MOD
            ans = (modPow(ans, 10) * modPow(a1, digit)) % MOD;
        }
        return ans;
    }
};
