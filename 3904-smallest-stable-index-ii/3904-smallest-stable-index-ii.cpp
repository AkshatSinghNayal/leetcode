class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(); 
        if(n == 0 ) return -1; 
        vector<int> suffix(n); 
        suffix[n-1]=nums[n-1]; 
        for(int i = n-2 ; i>= 0 ; i-- ){
            suffix[i]=min(nums[i], suffix[i+1]); 
        }
        int maxi = nums[0]; 
        for(int i  = 0; i<n ;i++ ){
            maxi = max(maxi , nums[i]); 
            if(maxi - suffix[i]  <= k ){
                return i; 
            }
        }
        return -1; 
    }
};