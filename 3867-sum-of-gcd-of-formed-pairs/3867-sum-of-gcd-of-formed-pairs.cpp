class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int maxi = 0 ; 

        for(int i = 0;i < n ;i++ ){
            maxi = max(maxi ,nums[i]); 
            prefix[i] = gcd(nums[i], maxi );
        }

        sort(prefix.begin(), prefix.end()); 
        int  i = 0 , j = n-1 ; 

        long long sum  = 0; 
        while( i < j ){
            sum += gcd(prefix[i], prefix[j]); 
            i++ ; j--; 
        }
        return sum ; 
    }
};