/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nums; 

        while(head){
            nums.push_back(head->val); 
            head = head->next;
        }
        int n = nums.size(); 
        int maxi = INT_MIN , mini = INT_MAX  , first = INT_MAX , last= INT_MIN;
        for(int i  =1 ;i<n-1 ; i++ ){
            if( nums[i] > nums[i-1] and nums[i] > nums[i+1 ]){
                
                if( first != INT_MAX ) maxi = max( maxi , i+1 - first);
                if(last != INT_MIN ) mini = min( mini , i+1 - last) ;
                first = min( first , i+1  );
                last = max( last , i+1 );  

            }
            else if( nums[i] < nums[i-1] and nums[i]  < nums[i+1]){
               
                if( first != INT_MAX ) maxi = max( maxi , i+1 - first);
                if(last != INT_MIN ) mini = min( mini , i+1 - last) ;
                first = min(first , i+1 ); 
                last = max( last , i+1 ); 
            }
        }
        vector<int>ans(2); 

        ans[0] = ( mini == INT_MAX ) ? -1 : mini ; 
        ans[1] = ( maxi  == INT_MIN ) ? -1 : maxi ; 

        return ans ;
    }
};