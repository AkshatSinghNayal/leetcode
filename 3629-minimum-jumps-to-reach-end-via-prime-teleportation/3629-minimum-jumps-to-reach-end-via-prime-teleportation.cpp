#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // 1. Find the maximum value to size our Sieve of Eratosthenes
        int MX = 0;
        for (int num : nums) {
            MX = max(MX, num);
        }
        if (MX < 2) MX = 2; // Prevent out-of-bounds if array is just 1s

        // 2. Build the Smallest Prime Factor (SPF) array using a Sieve
        // This allows us to factorize any number in O(log MX) time
        vector<int> spf(MX + 1);
        for (int i = 2; i <= MX; i++) spf[i] = i;
        
        for (int i = 2; i * i <= MX; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= MX; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // 3. Map every prime to the indices that are multiples of it
        // edges[p] will store all indices `i` where nums[i] is a multiple of `p`
        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            while (temp > 1) {
                int p = spf[temp]; // Get a prime factor
                edges[p].push_back(i);
                
                // Divide out all occurrences of this prime factor
                while (temp % p == 0) {
                    temp /= p;
                }
            }
        }

        // 4. Forward BFS
        queue<int> q;
        vector<bool> seen(n, false);
        vector<bool> visitedPrimes(MX + 1, false);

        q.push(0);
        seen[0] = true;
        int jumps = 0;

        while (!q.empty()) {
            int sz = q.size();
            
            // Process layer by layer
            while (sz--) {
                int curr = q.front();
                q.pop();

                if (curr == n - 1) {
                    return jumps;
                }

                // Move 1: Step Forward
                if (curr + 1 < n && !seen[curr + 1]) {
                    seen[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Move 2: Step Backward
                if (curr - 1 >= 0 && !seen[curr - 1]) {
                    seen[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Move 3: Prime Jump
                // Check if the current number is prime in O(1) using the SPF array
                int val = nums[curr];
                if (val >= 2 && spf[val] == val && !visitedPrimes[val]) {
                    visitedPrimes[val] = true; // Mark prime as used
                    
                    // Instantly jump to all multiples of this prime
                    for (int nextIdx : edges[val]) {
                        if (!seen[nextIdx]) {
                            seen[nextIdx] = true;
                            q.push(nextIdx);
                        }
                    }
                }
            }
            jumps++; // Increment jump count after finishing the current layer
        }

        return -1;
    }
};