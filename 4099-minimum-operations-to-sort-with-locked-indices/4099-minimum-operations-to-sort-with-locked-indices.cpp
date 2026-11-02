class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int mx=0,ops=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if((mx>i||nums[i]!=i+1)&&locked[i]){
                locked[i]=0;
                ops++;
            }
            mx=max(mx,nums[i]);
        }        
        if(ops>k)return -1;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ops+=(nums[i]>nums[j]);

        return ops;
    }
};
