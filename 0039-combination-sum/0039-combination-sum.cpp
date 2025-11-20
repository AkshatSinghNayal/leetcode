class Solution {
public:

    void solve(vector<int>& nums ,  vector<int>& temp , vector<vector<int>>& ans , int target , int index , int sum  ){
        
        if(  target == 0 ){
            ans.push_back(temp); 
            return ; 
        }
        if(  index >= nums.size() || target <0 ) return ; 

        temp.push_back(nums[index]); 
        solve( nums , temp , ans , target-nums[index] , index , sum+nums[index]); 
        temp.pop_back(); 
        solve( nums , temp , ans , target , index+1 , sum ) ;

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp ; 
        vector<vector<int>> ans ;
        solve( nums , temp , ans , target , 0 , 0 ) ; 
        return ans ; 
    }
};