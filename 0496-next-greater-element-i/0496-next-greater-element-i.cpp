class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n,-1);
        for( int i = 0 ; i<n ; i++){
            int k = find(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            for( int j = k ; j<nums2.size(); j++){
                if( (j)<nums2.size() && nums2[j]>nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};