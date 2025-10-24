class Solution {
public:

    int atMost( vector<int>& nums , int k ){
        int left =0 , right = 0 , odd = 0 , count =0 ; 
        int n = nums.size();

        while(right<n){

            if(nums[right]%2!=0){
                odd++;
            }
            while(odd>k){
                if(nums[left]%2!=0){
                    odd--;
                }
                left++;
            }

            count+= right-left+1;

            right++;
        }
        return count ;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost( nums , k ) - atMost(nums,k-1);
    }
};