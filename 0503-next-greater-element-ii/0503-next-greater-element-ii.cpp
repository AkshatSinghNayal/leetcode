class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>ans(n); 
        stack<int>st;
        for(int i  =  2*n-1 ; i>=0 ; i-- ){
            int index = i%n; 
            while(!st.empty() and st.top() <= nums[index]){
                st.pop();
            }
            if(!st.empty()){
                ans[index] = st.top(); 
            }
            else{
                ans[index] =-1;             }
            st.push(nums[index]); 
            
        }
        return ans; 
    }
};