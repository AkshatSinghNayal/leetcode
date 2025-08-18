// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
       stack<int> st; 
       vector<int> ans;
       
       
       for( auto n : arr){
            
            if(!st.empty() && st.top()>n){
                ans.push_back(n);
                st.pop();
            }
            else if(!st.empty() && st.top()<=n){
                ans.push_back(-1);
                st.pop();
            }
            
           
           st.push(n);
       }
       arr[arr.size()-1] = -1;
       for( int i = 0 ; i< ans.size() ; i++){
           arr[i] =ans[i];
       }

    }
};