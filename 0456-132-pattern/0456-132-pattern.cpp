class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st; 
        int n = nums.size() , right = n-1 ; 
        int theLeft = INT_MIN; 
        while(right>=0 ){

            if(theLeft>nums[right]){
                return true;
            }

            while(!st.empty() and st.top()<nums[right]){
                theLeft = st.top(); st.pop(); 
            } 
            
            
            
            st.push(nums[right]);
            right--; 
        }
        return false; 
    }
};