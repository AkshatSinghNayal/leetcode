class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int n = nums.size() , right = 0 , left = 0 ; 
        if( k> n ) return ans;
        while(right <n ){
            
            while(!dq.empty() and nums[dq.back()] < nums[right] ){
                dq.pop_back(); 
            }
            dq.push_back(right);
            
            if( right -left +1 == k ){
                ans.push_back(nums[dq.front()]);
                if( left == dq.front() ) dq.pop_front();
                left++;
            }

            right++; 
        }

        return ans ; 
    }
};