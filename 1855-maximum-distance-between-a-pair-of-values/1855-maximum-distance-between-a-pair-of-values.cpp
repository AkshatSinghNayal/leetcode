class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0; 
        int n  = nums1.size() ,m = nums2.size(); 
        int left = 0 , right = 0; 
        while( left < n and right < m ){
            while( right < m and left <= right and  nums1[left] <= nums2[right] ){
                maxi = max(maxi , right-left );
                right++; 
            }
            if( left > right ){
                right++;
                continue;
            }
            left++; 
        }
        return maxi; 
    }
};