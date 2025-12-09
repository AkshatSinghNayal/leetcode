class Solution {
public:


    int maxProduct(vector<int>& nums) {
        int n = nums.size();
    vector<int> maxProd(n), minProd(n);

    maxProd[0] = minProd[0] = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
        int x = nums[i];

        maxProd[i] = max({x, x * maxProd[i-1], x * minProd[i-1]});
        minProd[i] = min({x, x * maxProd[i-1], x * minProd[i-1]});

        ans = max(ans, maxProd[i]);
    }

    return ans;
    }
};