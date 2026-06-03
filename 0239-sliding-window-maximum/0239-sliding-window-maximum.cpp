class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq; 
        vector<int>ans;
        int n = nums.size(); 
        if( k == 1 ) return nums; 
        int left =0; 
        for(int right = 0; right<n ; right++ ){

            while( !dq.empty() and  nums[dq.back()]< nums[right] ) dq.pop_back(); 
            dq.push_back(right); 

            if( right -left +1 == k ){
                ans.push_back(nums[dq.front()]); 
                while( !dq.empty() and dq.front()<= left ) dq.pop_front(); 
                left++; 
            }

        }
        return ans; 
    }
};