class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
     set<int>s ;
     int i =0;
     int j=0;
     int n =nums1.size();
     int m = nums2.size();
     while(i<n && j<m){
        if(nums1[i]==nums2[j]){
            s.insert(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            i++;
        }
     }
     vector<int> v(s.begin(),s.end());
return v;
    }
};