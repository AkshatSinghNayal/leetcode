class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate( nums.begin() , nums.end() , 0);
        int total = nums.size(); 

        return ( (total*(total+1))/2 - sum); 
    }
};