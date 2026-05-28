class Solution {
public:

    bool solve(vector<int>& nums , int minIdx , int n ){
        int i = minIdx ; 
        for( ;i<n+minIdx ;i++ ){
            if( nums[i%n] != nums[(i+1)%n] -1) break;
        }
        if( (i+1)%n == minIdx ){
            return true; 
        }
        return false ;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size(); 
        int minIdx = 0; 
        for(int i = 0 ; i< n; i++ ){
            if( nums[i] == 0 ){
                minIdx = i; 
                break;
            }
        }

        int globalMinIdx = minIdx; 
        bool increasing = solve(nums, minIdx , n); 
        bool decreasing = false;

        if( !increasing){
            reverse(nums.begin() , nums.end() ) ; 
            minIdx = (n-1)-minIdx ;
            decreasing = solve(nums, minIdx , n) ;
        }

        if(!increasing and !decreasing ){
            return -1; 
        }
        int minOperations = n ; 
        if( increasing ){
            minOperations = min({minOperations , minIdx ,(n-1)-minIdx+3 } ); 
        }
        else{
            minOperations = min( {minOperations , (globalMinIdx+2) , minIdx+1 } ); 
        }
        cout<<n-minIdx;
        return minOperations ; 
    }
};