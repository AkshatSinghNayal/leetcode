class Solution {
public:
    
    void ssieve(vector<int>& ans , int i) {
        for (int j = i * i; j < ans.size(); j += i) {
            ans[j] = 1;  // mark composite
        }
    }
    void sieve() {
        int a = 0 ; 
    }

    vector<int> findPrimeFactors(int n) {
        vector<int> ans(n + 1, 0); // sieve array
        vector<int> factors;

        if (n <= 1) return factors;

        // build sieve
        for (int i = 2; i * i <= n; i++) {
            if (ans[i] == 0) {
                ssieve(ans, i);
            }
        }

        // factorization
        for (int i = 2; i < ans.size() && n > 1; i++) {
            if (ans[i] == 0) { // i is prime
                while (n % i == 0) {
                    factors.push_back(i);
                    n /= i;
                }
            }
        }

        if (n > 1) factors.push_back(n); // leftover prime > sqrt(n)

        return factors;
    }
};
