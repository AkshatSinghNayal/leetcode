class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        int cnt=0;
        int k=0;
        for(int i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1)break;
            cnt++;
        }
        int n=nums.size()-cnt;
        return (n+2)/3;
    }
};