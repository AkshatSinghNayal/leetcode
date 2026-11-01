class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        cout << mini << " ";
        int n = nums.size(); 
        for(int i  = 1; i<n ;i+=2){
            string first = to_string(nums[i-1]);
            string second = to_string(nums[i]); 
            int temp = stoi(first+second);
            mini= min(mini , temp);
        }
        return mini;
    }
};