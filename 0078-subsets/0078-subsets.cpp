class Solution {
public:

    void subsetHelper ( vector<int>& nums , vector<vector<int>>& ans , vector<int>& temp , int index){
        ans.push_back(temp);
        for( int i = index ; i<nums.size() ; i++){
            temp.push_back(nums[i]); 
            subsetHelper( nums , ans , temp , i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> temp ; 
        subsetHelper(nums , ans , temp , 0 ); 
        return ans ; 
    }
};