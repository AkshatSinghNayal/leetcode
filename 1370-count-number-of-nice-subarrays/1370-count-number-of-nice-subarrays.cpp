class Solution {
public:
    int atmost(vector<int>& nums, int k ){
        if(nums.size() < k ) return 0 ; 
        int left = 0 ; 
        int count = 0 ;
        int right = 0; 
        int oddCount = 0;
        while(right<nums.size()){
            if(nums[right]%2!=0){
                oddCount++;
            }
            while(oddCount>k){
                if(nums[left]%2!=0){
                    oddCount--;
                }
                left++;
            }
            
            count+=right-left+1;

            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atmost(nums,k)-atmost(nums,k-1);
    }
};