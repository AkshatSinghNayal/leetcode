class Solution {
public:


    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
    int currMin = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int x = nums[i];

        int tempMax = max({x, currMax * x, currMin * x});
        int tempMin = min({x, currMax * x, currMin * x});

        currMax = tempMax;
        currMin = tempMin;

        ans = max(ans, currMax);
    }

    return ans;
    }
};