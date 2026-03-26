class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>result(n);
        prefix[0] = nums[0]; 
        for(int i  =1 ;i < n;i++ ){
            prefix[i] = prefix[i-1]+nums[i]; 
        }

        for(int i = 0 ; i< n;i++ ){
            int left = prefix[i]-nums[i]; 
            int right = prefix[n-1]-prefix[i]; 

            int temp = abs(i*nums[i] - left );
            int temp1 =abs( ((n-1-i)*nums[i]) - right ); 

            result[i]=temp+temp1;

        }
        return result;

    }
};