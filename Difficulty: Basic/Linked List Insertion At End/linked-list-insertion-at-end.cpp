/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
       Node* newNode = new Node(x);

        // If the list is empty, new node becomes the head
        if (head == NULL) {
            return newNode;
        }

        // Traverse to the end of the list
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Link the last node to new node
        temp->next = newNode;

        return head;
    }
};