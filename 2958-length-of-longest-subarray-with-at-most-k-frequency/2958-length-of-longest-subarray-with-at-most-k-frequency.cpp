class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left =0 , right = 0, n = nums.size(); 
        int maxi = INT_MIN;
        while(right<n){
            mp[nums[right]]++;
            while( left<right and mp[nums[right]]>k ){
                mp[nums[left]]--;
                left++;
            }
            maxi = max(maxi , right-left+1); 
            // cout<< left << "->" << right << endl;
            right++; 
        }
        return maxi ; 
    }
};