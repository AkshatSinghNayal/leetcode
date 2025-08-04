class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp; 
        stack<int> st ; 
        for(int i = nums2.size()-1; i<nums2.size(); i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                mp[nums2[i]]=st.top();
            }
            else{
                mp[nums2[i]] =-1;
            }
            st.push(nums2[i]);
        }
        vector<int> ans ; 
        for( auto it: nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};