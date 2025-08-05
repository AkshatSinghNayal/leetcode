class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Iterate from 2n-1 to 0 to simulate circular array
        for(int i = 2*n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if(i < n) {  // Fill ans only for first n indices
                if(!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(curr);
        }

        return ans;
    }
};
