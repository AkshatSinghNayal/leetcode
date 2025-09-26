// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        
        vector<pair<int,int>> ans ;
        unordered_set<int> seen ;
        Node* temp = head ; 
        while(temp){
            int data = temp->data;
            int compliment = target-(data);
            if(seen.find(compliment) != seen.end()){
                ans.push_back({compliment,data}); 
            }
            seen.insert(data);
            temp=temp->next ;
        }
        sort(ans.begin(),ans.end());
        return ans ; 
    }
};