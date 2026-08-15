class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       vector<int> ans = nums;
        long long totalXor = 0;
        bool sabAnda = true;

        for (int i = 0; i < ans.size(); i++) {
            totalXor ^= ans[i];
            if (ans[i] != 0) sabAnda = false;
        }

        if (sabAnda == true) {
            return 0;
        }
            if (totalXor != 0) {
            return ans.size();
        }

        if (totalXor == 0) {
            return ans.size() - 1;
        }

        return 0;
    }
};