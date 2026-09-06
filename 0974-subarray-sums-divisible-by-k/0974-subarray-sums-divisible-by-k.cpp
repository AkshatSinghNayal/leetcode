class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp; 
        mp[0]=1; 
        int count =0;

        long long sum  =0 ; 
        for(auto& it : nums ){
            sum+=it; 
            long long comp = (sum%k+k)%k; 
            if(mp.count(comp)){
                count+=mp[comp]; 
            }
            mp[comp]++; 
        }
        return count;
    }
};