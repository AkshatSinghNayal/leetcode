class Solution {
public:
    void checker(vector<int>& ans, int i) {
        for (int j = i * i; j < ans.size(); j += i) {
            ans[j] = 1; // mark composite
        }
    }

    vector<int> primeFac(int n) {
        vector<int> ans1;
        if (n <= 1) return ans1;

        vector<int> ans(n + 1, 0); // sieve array (0 = prime)

        // sieve
        for (int i = 2; i * i <= n; i++) {
            if (ans[i] == 0) {
                checker(ans, i);
            }
        }

        // collect prime factors of n
        for (int i = 2; i <= n; i++) {
            if (ans[i] == 0 && n % i == 0) {
                ans1.push_back(i);
            }
        }

        return ans1;
    }
};
