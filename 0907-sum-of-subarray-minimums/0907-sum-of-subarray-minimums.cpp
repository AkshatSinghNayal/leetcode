class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int globalSum =0  , n = nums.size() ; 
        vector<int> prev(n) , next(n); 
        stack<int> st; 
        const int MOD = 1e9+7; 
        for(int i  = 0 ;i <  n;  i++ ){
            while(!st.empty() and nums[st.top()]> nums[i]){
                st.pop(); 
            }
            if(st.empty()){
                prev[i] =-1;
            }else{
                prev[i] = st.top(); 
            }

            st.push(i);
        }
        st = stack<int>(); 
        for(int i  =  n-1 ;i >=0 ; i-- ){

            while(!st.empty() and nums[st.top()]>=nums[i]){
                st.pop(); 
            }

            if(st.empty()){
                next[i] = n; 
            }
            else{
                next[i] = st.top(); 
            }
            st.push(i); 
        }
       
        for(int i =0 ;i <  n; i++ ){ 
            globalSum = (globalSum + 
        (1LL*(i - prev[i]) * (next[i] - i) % MOD * nums[i] % MOD)
    ) % MOD;
        }
        return globalSum;
    }
};