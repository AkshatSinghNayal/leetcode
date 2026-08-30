class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int,vector<int>>mp; 
        for(int i  = 0;i<n ; i++ ){
            mp[nums[i]].push_back(i);
        }
        int count =0 ; 
        for(auto& [it , ans] : mp){
            int m= ans.size();
            bool flag = true;
            if(m ==1) count++; 
            else{
                for(int i  = 0 ;i<m-1 ;i++ ){
                    if(ans[i+1]-ans[i] !=  1 ){
                        flag = false;
                    }
                }
                if(flag)count++;
            }
        }
        return count;
    }
};