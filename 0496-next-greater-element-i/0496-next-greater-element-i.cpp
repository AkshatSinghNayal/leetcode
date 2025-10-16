class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int j = nums2.size();
        vector<int> ans(j);
        j--;
        while (j >= 0) {

            while (!st.empty() && nums2[j] > st.top()) {
                st.pop();
            }
            if (st.empty()) {
                ans[j] = -1;
            } else {
                ans[j] = st.top();
            }
            st.push(nums2[j]);

            j--;
        }

        for (int i = 0; i < nums1.size(); i++) {
            int a = nums1[i];
            auto it = find(nums2.begin(), nums2.end(), a);
            int index = it - nums2.begin();
            nums1[i] = ans[index];
        }
        return nums1;
    }
};