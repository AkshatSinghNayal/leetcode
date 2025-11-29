class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(),nums.end() , 0); 

return sum%k ;
    }
};