/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
       
        Node* newNode = new Node(data);
       int i = 0 ; 
       Node* temp = head ; 
       
       while( temp && i < pos){
           temp = temp->next; 
           i++;
       }
           if (temp == nullptr && i != pos) {
            return head;
        }
        Node* after = temp->next;
        temp->next = newNode ;
        newNode->prev = temp;
        
        if(after!=nullptr){
            newNode->next = after ; 
            after->prev=newNode;
        }
        
        
        return head;
    }
};