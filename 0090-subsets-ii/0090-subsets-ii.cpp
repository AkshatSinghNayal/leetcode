class Solution {
public:

    void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]); 
        solve( index + 1 ,  nums , temp , ans ); 
        temp.pop_back(); 
        while( index+1 < nums.size() && nums[index] == nums[index+1]) index++; 
        solve(index+1 , nums, temp , ans) ; 
       
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums, temp, ans);
        return ans;
    }
};
