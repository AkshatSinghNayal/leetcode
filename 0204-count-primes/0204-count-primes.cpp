class Solution {
public:
    void checker(vector<int>& ans, int i) {
        for (int j = i * i; j < ans.size(); j += i) {
            ans[j] = 1; // mark as not prime
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<int> ans(n, 0); // 0 = prime candidate
        for (int i = 2; i * i < n; i++) {
            if (ans[i] == 0) {
                checker(ans, i);
            }
        }

        int count = 0;
        for (int i = 2; i < ans.size(); i++) { // start from 2
            if (ans[i] == 0) {
                count++;
            }
        }
        return count;
    }
};
