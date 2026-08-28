class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        long long maxi = LLONG_MIN;
        sort(nums.begin() , nums.end()); 
        
        maxi = max({maxi , 1LL*-100000*nums[n-1]*nums[n-2]});
        maxi = max({maxi , 1LL*100000*nums[n-1]*nums[n-2]}); 
        maxi = max({maxi , 1LL*-100000*nums[0]*nums[1]}); 
        maxi = max({maxi , 1LL*100000*nums[0]*nums[1]}); 
        maxi = max({maxi , 1LL*100000*nums[0]*nums[n-1]}); 
        maxi = max({maxi , 1LL*-100000*nums[0]*nums[n-1]}); 


        return maxi ; 


    }
};