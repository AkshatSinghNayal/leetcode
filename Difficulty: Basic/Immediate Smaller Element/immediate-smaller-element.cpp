// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& nums) {
      int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        // Iterate from 2n-1 to 0 to simulate circular array
        for(int i = n - 1; i >= 0; i--) {
        int takenAtFirst =1;  
            
                if(!st.empty() && st.top()>=nums[i]){
                    ans[i] = -1 ; 
                    st.top();
                    takenAtFirst=0;
                }


            
                if(!st.empty() && takenAtFirst == 1) {
                   
                    ans[i] = st.top();
                  
                }
            

            st.push(nums[i]);
        }

       for( int i = 0 ; i <nums.size() ; i++){
           nums[i] = ans[i];
           
       }
           
    }
};