class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int counter = nums1[0] ; 
        int i  = 0 , j = 0 ; 
        int n  = nums1.size() , m = nums2.size(); 
        while( i < n and j<m ){
            if( j< m and counter  == nums2[j]){
                return counter; 
            }
            else if( counter< nums2[j]){
                if( i+1 < n ) counter = nums1[i+1];
                i++;  
            }
            else{
                j++;  
            }
        }
        return -1 ; 
    }
};