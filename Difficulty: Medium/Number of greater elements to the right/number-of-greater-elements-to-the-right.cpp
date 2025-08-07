
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        stack<int> st; ;
        vector<int> ans ; 
            for(int j = 0;  j<indices.size() ; j++){
                int value = arr[indices[j]]; 
             for(int i = indices[j]+1 ; i<n ; i++){
                    
                if(value<arr[i]){
                    st.push(arr[i]);
                }
               
                
            }
            ans.push_back(st.size());
            st = stack<int>();
        }
        return ans ;
    }
};