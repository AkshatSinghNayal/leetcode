// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(),bt.end());
        long long total = 0 ; 
        
        long long sum = 0 ; 
        for( int i =0 ; i<bt.size()-1 ; i++){
            sum+=bt[i]; 
            total+=sum; 
            
        }
        int n = bt.size() ;
        long long ans  = total/n ; 
        return ans ; 
    }
};