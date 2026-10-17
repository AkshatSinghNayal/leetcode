class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n  = nums.size(); 
        vector<int>maxi(n);
        maxi[n-1] = nums[n-1];
        for(int i  = n-2; i>=0; i-- ){
            maxi[i] = max(maxi[i+1],nums[i]); 
        }

        int i=0; 
        int j =0 ; 
        int ans = 0; 

        while(i<n){
            int ele = nums[i]; 

            while(j<n and maxi[j] >= ele){
                ans = max(ans, j-i); 
                j++; 
            }
            i++; 
        }
        return ans;
    }
};