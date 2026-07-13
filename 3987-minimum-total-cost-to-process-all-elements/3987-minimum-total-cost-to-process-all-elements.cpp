class Solution {
public:
    const long long MOD = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k1) {
        unsigned long long count = 0;
        unsigned long long k = k1; 
        long long last = 0;

        for (int it : nums) { 
            if (it > k) {
                long long total = (it - k + k1 - 1) / k1;

                long long term = (total % MOD) * ((2 * (last % MOD) + (total % MOD) + 1) % MOD) % MOD;
                term = (term * 500000004LL) % MOD; 

                count = (count + term) % MOD;
                last = (last + total) % MOD;
                
                k += (unsigned long long)total * k1; 
            }
            k -= it;
        }
        return count;
    }
};