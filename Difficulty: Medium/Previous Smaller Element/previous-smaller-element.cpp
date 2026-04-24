class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size(); 
        stack<int>st; 
        for(int i = 0  ; i< n; i++ ){
            while(!st.empty() and st.top()>= arr[i]) st.pop(); 
            int temp =-1; 
            if(!st.empty())temp = st.top();
            st.push(arr[i]); 
            arr[i] = temp; 
        }
        return arr; 
    }
};