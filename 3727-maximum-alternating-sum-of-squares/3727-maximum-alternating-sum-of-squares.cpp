class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(); 
        int gotll = n/2;

        long long total = 0; 
        sort(nums.begin(), nums.end(),[&](const auto& a , const auto& b ){
            return abs(a) < abs(b);
        }); 
        int i = 0; 
        while(i<gotll){
            total-=(nums[i]*nums[i]);
            i++; 
        }
        while(i<n){
            total+=(nums[i]*nums[i]);
            i++; 
        }
        return total;
    }
};