class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st ; 
        unordered_map<int,int> mp ;

        for ( auto n : nums2){
            while(!st.empty()  && st.top()<n){
                mp[st.top()] = n; 
                st.pop();
            }



            st.push(n);
        }

        vector<int> ans; 
        for( auto x : nums1){
            if(mp.find(x) == mp.end()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[x]);
            }
        }
        return ans;
    }
};