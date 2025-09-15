class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans;
        int right = (2 * n )- 1;
        while (right >= 0) {

            while (!st.empty() && st.top() <= nums[right%n]) {
                st.pop();
            }
            if (right < n ) {
                if (!st.empty()) {
                    ans.push_back(st.top());
                } else {
                    ans.push_back(-1);
                }
            }
            st.push(nums[right%n]);
            right--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};