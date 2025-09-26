// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* temp = *head_ref ; 
        
        while( temp ){
            if(temp->data == x ){
                Node* after = temp->next ; 
                Node* before = temp->prev ; 
                
                if( temp == *head_ref ){
                    *head_ref = after ; 
                    delete temp ; 
                    temp = after ; 
                    continue ;
                }
                if( before ) before->next = after ; 
                if(after) after->prev =before ; 
                delete temp ; 
                temp = after ; 
                continue ; 
            }
            temp= temp->next ;  
        }
       
    }
};