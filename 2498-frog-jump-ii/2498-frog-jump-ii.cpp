class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;

        // handle adjacent difference (important for n=2)
        for (int i = 1; i < n; i++) {
            ans = max(ans, stones[i] - stones[i - 1]);
        }

        // main greedy (skip one)
        for (int i = 2; i < n; i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }

        return ans;
    }
};