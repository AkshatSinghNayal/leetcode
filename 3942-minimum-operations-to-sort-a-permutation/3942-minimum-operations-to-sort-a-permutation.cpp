class Solution {
    bool checkIfIncreasing(vector<int>& nums,int& min_idx,int& n){
        int i;
        for(i=min_idx;i<min_idx+n;++i){
            if(nums[(i+1)%n]-1 != nums[i%n])
                break;
        }
        if((i+1)%n == min_idx)
            return true;
        return false;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        //Step-1: Find min_idx
        int min_idx;
        int i;
        for(i=0;i<n;++i)
            if(nums[i]==0){
                min_idx = i;
                break;
            }
        
        //Step-2: Find if increasing or decreasing ?
        bool is_increasing = checkIfIncreasing(nums,min_idx,n);
        bool is_decreasing = false;
        if(!is_increasing){
            reverse(nums.begin(),nums.end());
            min_idx = n-min_idx-1;
            is_decreasing = checkIfIncreasing(nums,min_idx,n);
        }
        if(!is_increasing and !is_decreasing)
            return -1;

        //Step-3: Calculate min_operations
        int min_ops = n;
        if(is_increasing){
            min_ops = min(min_idx, 2+n-min_idx);
        }else{
            min_ops = min((1+min_idx), 1+(n-min_idx));
        }
        return min_ops;
    }
};