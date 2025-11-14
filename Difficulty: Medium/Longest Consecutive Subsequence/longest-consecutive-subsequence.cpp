class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& nums) {
        int count = 1 ; 
        int maxi = INT_MIN ; 
        unordered_set<int> st(nums.begin(),nums.end()); 
        
        for( const auto& it : st){
            count = 1; 
            int num = it-1 ;
            int temp = it ; 
            if(st.find(num) == st.end()){
                while(st.find(temp+1) != st.end()){
                    count++; 
                    temp++; 
                    
                }
                maxi = max( maxi , count); 
            }
        }
        return (maxi == INT_MIN ) ? 0 : maxi ; 
    }
};