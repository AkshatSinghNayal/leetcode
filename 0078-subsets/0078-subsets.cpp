class Solution {
public:

    void subsetHelper(vector<int>& nums , vector<int>& temp, vector<vector<int>>& ans , int index  ) {

        if( index >= nums.size()){
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[index]);
        subsetHelper( nums , temp , ans , index+1);
        temp.pop_back() ; 
        subsetHelper( nums , temp , ans , index+1);


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ; 
        vector<int> temp ; 

        subsetHelper( nums ,temp , ans , 0);

        return ans ; 
    }
};