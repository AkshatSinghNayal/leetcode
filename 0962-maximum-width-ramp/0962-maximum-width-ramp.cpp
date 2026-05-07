class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(); int maxi = 0; 
        stack<int>st; 
        for(int i =n-1; i>=0 ;i-- ){
            if(!st.empty() and nums[st.top()] >=nums[i] ) continue;
            st.push(i); 
        }
        for(int i  = 0 ;i < n; i++ ){
            while(!st.empty() and nums[i] <= nums[st.top()]) {
                maxi = max(maxi , st.top() - i ); 
                st.pop(); 
            }
            if(st.empty()) break;
        }
        return maxi; 
    }
};