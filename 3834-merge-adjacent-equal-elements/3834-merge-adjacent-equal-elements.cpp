class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size();
        int i = 0;
        while (i < n) {
           
            long long ele = nums[i];
                while (!ans.empty() and ans.back() == ele) {
                    long long temp = 1LL * 2 * ele;
                    ans.pop_back();
                    ele = temp;
                }
            ans.push_back(ele);
            i++;
            }
        
        return ans;
    }
};