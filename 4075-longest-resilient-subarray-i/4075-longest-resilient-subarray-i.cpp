class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size(); 
        int sum = 0;
        int prev = -1; 
        int last =  0;
        int maxi = INT_MIN;
        for(int i = 0 ;i<n; i++ ){
            int rem = nums[i]%k; 
            sum+=nums[i]; 
            if( prev != rem ){
                prev = nums[i]%k;
                sum=nums[i]; 
                last = i; 
            }
            else{
                if((sum-rem)%k == 0 ) maxi=max(maxi, i-last+1 );
            }
        }
        return maxi == INT_MIN ? 1 : maxi;
    }
};