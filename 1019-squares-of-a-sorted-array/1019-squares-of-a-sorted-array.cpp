class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pos = n - 1;
        vector<int> temp(nums); // make a copy of original for reading

        while (left <= right) {
            int leftSq = temp[left] * temp[left];
            int rightSq = temp[right] * temp[right];
            if (leftSq > rightSq) {
                nums[pos--] = leftSq;
                left++;
            } else {
                nums[pos--] = rightSq;
                right--;
            }
        }
        return nums;
    }
};
