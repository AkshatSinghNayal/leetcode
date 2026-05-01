#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n = nums.size(); vector<int>ans;
        for(int  i = 0;i<n; i++ ){

            while( !dq.empty() and nums[dq.back()]<nums[i] ) dq.pop_back(); 
            dq.push_back(i); 
            while( !dq.empty() and i-k>= dq.front()) dq.pop_front(); 
            if( i >= k-1 ){
                ans.push_back(nums[dq.front()]); 
            } 
        } 
        return ans; 
    }
};