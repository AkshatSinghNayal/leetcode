class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            // If stack is not empty, then top is the next greater
            if (!st.empty()) {
                ans[i] = st.top();
            }
            // Push current element to stack
            st.push(arr[i]);
        }

        return ans;
    }
};
