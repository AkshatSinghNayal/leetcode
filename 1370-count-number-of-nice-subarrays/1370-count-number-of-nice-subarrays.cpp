class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int left = 0, count = 0;
        int oddCount = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] & 1) oddCount++;  // bitwise odd check

            while(oddCount > k){             // shrink window from left
                if(nums[left] & 1) oddCount--;  // check left with bitwise
                left++;
            }

            count += right - left + 1;       // all valid subarrays ending at right
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k){
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
