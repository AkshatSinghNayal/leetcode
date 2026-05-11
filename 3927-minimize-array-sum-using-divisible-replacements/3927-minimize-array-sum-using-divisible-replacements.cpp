class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long ans = 0; int n = nums.size();
        sort(nums.begin() , nums.end());  
        const int MAX = nums[n-1]; 
        vector<long long>freq(nums[n-1]+1,0);
        vector<long long>best(nums[n-1]+1,-1);

        for(auto& it : nums ){
            freq[it]++;
        }

        for(int i = 0; i<n ; i++ ){
            int ele = nums[i]; 
            if(freq[ele] == 0 ) continue;

            for(int i = ele ; i<=MAX ; i+=ele){
                if(freq[i]>0){
                    freq[i] = 0; 
                    best[i] = ele; 
                }
            }

        }
        for(auto& it : nums ){
            ans+=best[it]; 
        }
        return ans; 

    }
};