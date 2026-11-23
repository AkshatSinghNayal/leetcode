class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size(); 
        if( n== 1 ) return 1;
        int count =0;

        count = ( n>1 and nums[0] >= nums[1]) ? 1 : 0; 
        count = ( n-2>=0 and nums[n-1] >= nums[n-2]) ? count+1 : count;

        for(int i = 1;i<n-1; i++ ){
            if( (float)(nums[i-1]+nums[i+1]*1.0)/2 <= (float)nums[i] ) count++;
        }
        return count;
    }
};