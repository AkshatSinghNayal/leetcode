class Solution {
public:

    vector<vector<int>>ans;
    vector<int>temp; 

    void solve(vector<int>& candidates , int target , int sum, int i ){
        //base
        if( i>=candidates.size() ) return ;

        if( sum == target ){
            ans.push_back(temp); 
            return;
        }


        if( sum+candidates[i] <= target ){
            temp.push_back(candidates[i]);
            solve(candidates, target , sum+candidates[i] , i); 
            temp.pop_back();
        }
        solve(candidates, target , sum , i+1 ); 
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve( candidates , target , 0 , 0); 
        return ans; 
    }
};