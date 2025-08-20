class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        st = stack<int>(); // reset the stack ✅

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (long long)arr[i] * left[i] * right[i];
            res = (res + contrib) % MOD;
        }

        return (int)res;
    }
};
