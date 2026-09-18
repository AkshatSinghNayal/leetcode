class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //till this point i whats the max and min product of the subarray 
        int n =  nums.size(); 
        // vector<int>maxi(n),mini(n);
        // maxi[0]= mini[0] = nums[0];
        int maxi = nums[0] ;  int mini = nums[0];
        int maxProduct = maxi;

        for(int i = 1  ;i<n; i++ ){
            int x = nums[i]; 

            int currentMax = max({x , x*maxi , x*mini});
            int currentMin = min({x , x*maxi, x*mini}); 
            maxi = currentMax; mini= currentMin;
            maxProduct = max(maxProduct , currentMax); 

        }
        return maxProduct;
    }
};