class Solution {
public:

    void combinationSumHelper( vector<int>& candidates, int target , vector<vector<int>>& ans, vector<int>& temp , int index ){

        if( target == 0){
            ans.push_back(temp) ;
        }
        if( target<0) return ; 


        while( index < candidates.size()){
            temp.push_back(candidates[index]);
            combinationSumHelper( candidates , target-candidates[index] , ans , temp, index );
            temp.pop_back() ; 
            index++;
        }


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ; 
        vector<int> temp ; 

        combinationSumHelper( candidates , target , ans , temp , 0);

        return ans ; 
        
    }
};