class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp; 
        for(auto& it : nums1){
            mp[it]++; 
        }

        for(auto& it : nums2 ){
            if(mp.count(it)){
                return it ; 
            }
        }
        return -1 ; 
    }
};