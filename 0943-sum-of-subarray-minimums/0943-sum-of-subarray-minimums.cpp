class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        int result = 0;
        
        vector<int> leftSmallest(n), rightSmallest(n);
        stack<int> st;

        for( int i = 0 ; i<arr.size() ; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            leftSmallest[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
           st = stack<int>(); 

           for( int j = arr.size()-1 ; j>= 0 ; j--){
            while(!st.empty() && arr[st.top()]>=arr[j]  ){
                st.pop();
            }
            rightSmallest[j] = st.empty() ? n : st.top() ;
            st.push(j) ;
           }


           for( int i = 0 ; i<arr.size(); i++){
                int left = i - leftSmallest[i];
                int right = rightSmallest[i] - i ;
                long long count = (long long)left*right*1ll*arr[i];
                 result= (result+count)%MOD;
           }

        return (int)result;
       
    }
};
