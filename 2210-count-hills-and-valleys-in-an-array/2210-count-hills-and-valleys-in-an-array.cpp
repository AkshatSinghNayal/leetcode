class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i  =0  , n = nums.size(); 
        vector<int>ans;
        while( i < n ){
            int ele = nums[i]; 
            int j = i+1; 
            while( j< n and nums[j] == ele){
                j++;
            }
            ans.push_back(ele);
            i=j;
        }
        i = 1;n=ans.size();
        int count =0; 

        while(i<n-1){
            count = ((ans[i] > ans[i-1] and ans[i] > ans[i+1]) or (ans[i] < ans[i-1] and ans[i] < ans[i+1])) ? count+1 : count;
            i++; 
        }

        // for(auto& it : ans) cout<<it<< " ";

        return count;
    }
};