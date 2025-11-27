class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> pre(n+1,0);

        long long sol=LLONG_MIN;

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }

        for(int i=0;i<k && i<n;i++){
            long long sum=0;
            for(int j=i;j+k<=n;j+=k){
                long long curr_sum= pre[j+k]-pre[j];
                
                sum = max(curr_sum,sum+curr_sum);
                sol = max(sol,sum);
            }
        }

        return sol;
    }
};