class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; 
        unordered_map<int,int> mp;
        int n = nums.size(); 

        vector<int> ans;  // Empty vector to hold 2n elements
        vector<int> ans1(n, -1);  // Final answer array

        // Manually doubling nums into ans vector
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        // Process from right to left
        for(int i = (2*n - 1); i >= 0; i--) {
            while(!st.empty() && st.top() <= ans[i]) {
                st.pop();
            }

           
                if(!st.empty()) {
                    mp[i] = st.top();
                } else {
                    mp[i] = -1;
                }
            

            st.push(ans[i]);
        }

        // Build ans1 using map
        for(int i = 0; i < n; i++) {
            ans1[i] = mp[i];
        }

        return ans1;
    }
};
