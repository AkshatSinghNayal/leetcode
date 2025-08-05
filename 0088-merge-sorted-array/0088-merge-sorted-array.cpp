class Solution {
public:
    
    void mergeSort(vector<int>& nums1,  vector<int>& nums2 , vector<int>& temp){
        int i = 0 ; int j =0;
        while( i <(nums1.size()-nums2.size()) && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<(nums1.size()-nums2.size())){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            temp.push_back(nums2[j]); 
            j++;
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        mergeSort( nums1 , nums2 , v);

        for(int i = 0 ; i<v.size(); i++){
            nums1[i] = v[i];
        }
    }
};