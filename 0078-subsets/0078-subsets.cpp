class Solution {
public:

    void subsetHelper ( vector<int>& nums , vector<vector<int>>& ans , vector<int>& temp , int index){
        
        if( index >= nums.size()){
            ans.push_back(temp);
            return; 
        }

        temp.push_back(nums[index]); 
        subsetHelper( nums , ans , temp , index+1); 
        temp.pop_back(); 
        subsetHelper( nums , ans , temp , index+1); 
        
        
        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> temp ; 
        subsetHelper(nums , ans , temp , 0 ); 
        return ans ; 
    }
};