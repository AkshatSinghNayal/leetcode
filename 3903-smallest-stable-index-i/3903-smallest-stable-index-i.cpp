class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n  =  nums.size() ;
        vector<int> track(n);

        track[n-1] = nums[n-1]; 
        for(int i = n-2 ;i>=0 ;i-- ){
            track[i] = min(nums[i],track[i+1]); 
        }

        int maxi = INT_MIN;
        for(int i= 0 ;i<n ;i++ ){
            maxi = max(maxi , nums[i]); 
            if( maxi - track[i] <= k ) return i; 
        }
        return -1;
    }
};