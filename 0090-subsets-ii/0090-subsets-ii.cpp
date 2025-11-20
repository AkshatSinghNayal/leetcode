class Solution {
public:

    void helperFunction( vector<int>& nums , vector<int>& temp , vector<vector<int>>& ans , int index ){
        ans.push_back(temp) ; 
        for( int i = index ;i<nums.size() ; i++){
            if( i > index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]); 
            helperFunction( nums , temp , ans , i+1); 
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        vector<int> temp ;
        vector<vector<int>> ans ; 

        helperFunction( nums , temp , ans , 0 ); 
        return ans ; 
    }
};