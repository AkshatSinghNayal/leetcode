class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left = 0  , right = nums.size()-1 ; long long maxi = LLONG_MIN; 
        int n = nums.size(); 
        while( left < right and right >= 0 and left < n ){
            int length = right-left; 
            long long cost = min(nums[right] , nums[left])*1LL*length; 
            cout << nums[left] << " " << nums[right]; 
            cout<<endl;

            if( nums[left] <= nums[right]) left++; 
            else right--;

            maxi = max(maxi , cost ); 
        }
        return (int)maxi ; 
    }
};