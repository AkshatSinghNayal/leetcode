class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin() , nums.end()); 
        int maxi = INT_MIN;

        for(int i = 0 ;i<n; i++ ){
            maxi = max(maxi , nums[(i+0)%n]*nums[(i+1)%n]*nums[(i+2)%n]); 
        }

        return maxi ; 
    }
};