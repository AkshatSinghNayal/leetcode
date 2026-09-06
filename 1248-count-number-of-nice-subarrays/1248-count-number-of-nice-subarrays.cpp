class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp ; 
        mp[0]=1;
        int count = 0;
        long long sum= 0; 

        for(auto& it : nums ){
            sum = ( it&1 ) ? sum+1 : sum ; 
            int needed = sum-k;

            if(mp.count(needed)){
                count+=mp[needed]; 
            }
            mp[sum]++;
        }
        return count;
    }
};