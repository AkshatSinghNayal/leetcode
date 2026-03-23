class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX; 
        for(auto& it : nums){
            if( abs(ans) > abs(it)){
                ans = it  ; 
            }
            else if (abs(ans) == abs(it)){
                if( ans < it ){
                    ans = it; 
                }
            }
            
        }
        return ans;
    }
};