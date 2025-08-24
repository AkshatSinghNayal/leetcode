class Solution {
public:

    void subsetsWithDup(vector<int>&nums , vector<vector<int>>& ans , vector<int>&temp, int index){

        ans.push_back(temp);
        for( int i = index ; i<nums.size() ; i++){
            if( index < i && nums[i] == nums[i-1]) continue ;
            temp.push_back(nums[i]); 
            subsetsWithDup( nums , ans , temp , i+1);
            temp.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans ; 
        vector<int> temp ; 

        subsetsWithDup( nums , ans , temp , 0 );
        return ans;
    }
};