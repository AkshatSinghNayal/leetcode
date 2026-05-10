class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>ans(n*2);
        int i = 0 , j =2*n-1; 
        while(i<n and j>=0 ){
            ans[j] = ans[i] = nums[i]; 
            i++; j--; 
        } 
        return ans; 
    }
};