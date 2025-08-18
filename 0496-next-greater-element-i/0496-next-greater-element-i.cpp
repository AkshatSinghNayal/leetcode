class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; 
        unordered_map<int,int> mp;
        int n = nums2.size()-1 ; 
        vector<int> ans;
        while(n>=0){

            while(!st.empty() && st.top()<nums2[n]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[n]){
                mp[nums2[n]] = st.top();
            }
            

            st.push(nums2[n]);
            n--;
        }

       for( auto x : nums1){
        if(mp.find(x) == mp.end()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(mp[x]);
        }
       }

    return ans ; 



    }
};