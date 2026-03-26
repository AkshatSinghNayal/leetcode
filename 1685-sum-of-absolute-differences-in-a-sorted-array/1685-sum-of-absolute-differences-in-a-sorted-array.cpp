class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin() , nums.end() , 0LL ); 
        long long left = 0; 
        vector<int>result(n);
        
        for(int i = 0 ; i< n;i++ ){
            int temp = total-left-nums[i]; 
            result[i] = (temp - nums[i]*((n-1)-i))+(nums[i]*i - left );
            left+=nums[i];
        }
        return result;

    }
};