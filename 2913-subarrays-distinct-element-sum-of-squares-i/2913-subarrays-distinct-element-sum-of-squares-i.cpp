class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int total = 0; 
        unordered_set<int>st;
        for(int i  = 0 ; i< n; i++ ){
            st.clear();
            for(int j  =i;  j<n ; j++ ){
                int ele = nums[j]; 
                if(!st.count(ele)){
                    st.insert(ele);
                }
                total+=(st.size()*st.size()); 
            }

        }
        return total;
    }
};