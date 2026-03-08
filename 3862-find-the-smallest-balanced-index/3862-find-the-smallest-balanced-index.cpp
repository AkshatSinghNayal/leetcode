class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long  product = 1;
        int index = -1;
        int n = nums.size();
        vector<long long> prefix(n+1);
        prefix[0] = 0; 
        for( int i  =1 ; i<=n; i++ ) prefix[i] = nums[i-1]+prefix[i-1]; 

        // for(auto& it : prefix ) cout << it << " "; 
        long long LIMIT = 1e14;
        for(int i  = n-1 ; i>=0 ; i-- ){
            if( product == prefix[i]){
                index = i;
            }
            if(product > LIMIT / nums[i])
                product = LIMIT + 1;
            else
                product *= nums[i];
        }

        return index;
    }
};