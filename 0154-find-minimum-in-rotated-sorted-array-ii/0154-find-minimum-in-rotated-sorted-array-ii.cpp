class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = *min_element(nums.begin(),nums.end());
        return ans; 
    }
};