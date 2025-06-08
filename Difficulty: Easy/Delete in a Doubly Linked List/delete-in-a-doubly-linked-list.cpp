/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        
        Node* temp = head ; 
        int i = 0; 
        if( x == 1 ){
            Node* del = head ; 
            head= head->next ; 
            if(head) head->prev= nullptr ; 
            delete(del);
            return head ; 
        }
        while(temp && i<(x-1)){
            i++; 
            temp = temp->next ; 
        }
        
        if( temp == nullptr) return head ; 
        
        Node* after = temp->next ; 
        Node* before = temp->prev ; 
        
        if(after) after->prev = before ; 
        if(before) before->next = after ; 
        
        return head; 
        
    }
};