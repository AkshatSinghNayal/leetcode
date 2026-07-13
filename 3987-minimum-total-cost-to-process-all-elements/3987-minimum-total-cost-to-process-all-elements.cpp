class Solution {
public:
    int minimumCost(vector<int>& nums, int k1) {
        const long long MOD = 1e9 + 7;

        long long cost = 0;
        long long resources = k1;
        long long operations = 0;

        for (long long x : nums) {
            if (resources < x) {
                long long need = (x - resources + k1 - 1) / k1;

                long long a = need;
                long long b = 2 * operations + need + 1;

                if (a % 2 == 0)
                    a /= 2;
                else
                    b /= 2;

                long long add = ((a % MOD) * (b % MOD)) % MOD;

                cost = (cost + add) % MOD;

                operations += need;
                resources += need * k1;
            }

            resources -= x;
        }

        return cost;
    }
};