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
    int pairSum(ListNode* head) {
        vector<ListNode*> nums; 
        ListNode*temp = head; 

        while(temp){
            nums.push_back(temp); 
            temp=temp->next;
        }
        int n = nums.size(); 
        int i  =  0 , j = n -1 ;
        long long maxi = INT_MIN; 
        while( i<j ){
            long long sum = nums[i]->val + nums[j]->val ;; 
            maxi = max(sum , maxi ); 
            i++ ; j--; 
        }
        return (int)maxi ;
    }
};